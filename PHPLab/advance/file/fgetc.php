<?php

// fgetc 读取一个字符

$file = fopen("sometext.txt", "r") or die("fail to open file");

do
{
    $ch = fgetc($file);
    echo $ch;
} while (!feof($file));

fclose($file);

?>