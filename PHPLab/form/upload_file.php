<?php

// 错误代码
// 0        没有错误发生
// 1        文件大小超过了 php.ini 中 upload_max_filesize 设置
// 2        文件超过了HTML表单中MAX_FILE_SIZE设置
// 3        文件只有部分被上传
// 4        未上传文件
// 6        临时目录不存在
// 7        写入磁盘出错
// 8        上传文件的扩展名被阻止

if ($_FILES["file"]["errpr"] > 0)   // 上传发生错误的错误代码
{
    echo "Error: " . $_FILES["file"]["errpr"] . "<br>";
}
else
{
    echo "Upload: " . $_FILES["file"]["name"] . "<br>"; // 文件在用户计算机上使用的名字
    echo "Type: " . $_FILES["file"]["type"] . "<br>";   // 文件的MIME类型
    echo "Size: " . $_FILES["file"]["size"] / 1024 . "kib<br>"; // 文件的大小
    echo "Stored in: " . $_FILES["file"]["tmp_name"]; // 临时文件，会在脚本结束时被删掉

    // 保存（到当前脚本目录）
    $ret = move_uploaded_file($_FILES["file"]["tmp_name"],
    "/data/tmp/" . $_FILES["file"]["name"]);
    if ($ret)
    {
        echo '<p style="color:green;">[OK] upload succ</p>';
    }
    else
    {
        echo '<p style="color:red;">[FAIL] upload fail</p>';
    }
}

?>