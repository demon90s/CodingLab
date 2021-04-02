<?php

// fgets 读取文件的一行

$file = fopen("sometext.txt", "r") or die("fail to open file");

do
{
    $line = fgets($file);
    echo $line . "<br>";
} while (!feof($file));

fclose($file);

?>