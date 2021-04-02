<?php

$file = fopen("sometext.txt", "r");
if (empty($file))
{
    die("open file failed");
}

$txt = fread($file, filesize("sometext.txt"));
echo "file content: " . $txt . "<br>";

fclose($file);

?>