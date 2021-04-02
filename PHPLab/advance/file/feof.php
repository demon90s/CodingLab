<?php

// feof 测试文件是否达到了文件尾

$file = fopen("sometext.txt", "r") or die("fail to open file");

do
{
    $line = fgets($file);
    echo $line . "<br>";
} while (!feof($file));

fclose($file);

?>