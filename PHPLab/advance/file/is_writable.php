<?php

// 文件不存在或者不可写都会 return false

$file = "readonly_tmp.txt";
if (is_writable($file))
{
    echo "$file can write<br/>";
}
else
{
    echo "$file can not write<br/>";
}

$file = "tmp.txt";
if (is_writable($file))
{
    echo "$file can write<br/>";
}
else
{
    echo "$file can not write<br/>";
}

$file = "nonexist_tmp.txt";
if (is_writable($file))
{
    echo "$file can write<br/>";
}
else
{
    echo "$file can not write<br/>";
}

?>