<?php

if ($_FILES["file"]["errpr"] > 0)
{
    echo "Error: " . $_FILES["file"]["errpr"] . "<br>";
}
else
{
    echo "Upload: " . $_FILES["file"]["name"] . "<br>";
    echo "Type: " . $_FILES["file"]["type"] . "<br>";
    echo "Size: " . $_FILES["file"]["size"] / 1024 . "kib<br>";
    echo "Stored in: " . $_FILES["file"]["tmp_name"]; // 临时文件，会在脚本结束时被删掉

    // 保存（到当前脚本目录）
    move_uploaded_file($_FILES["file"]["tmp_name"],
    "./" . $_FILES["file"]["name"]);
}

?>