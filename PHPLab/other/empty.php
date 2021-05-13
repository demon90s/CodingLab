<?php

// 测试 empty
// Determine whether a variable is considered to be empty. A variable is considered empty if it does not exist or if its value equals false.

if (empty($nothisvar))
{
    echo "nothisvar is empty~~~<br/>";
}

if (empty(true))
{
    echo "true is empty??<br/>";
}

if (empty(false))
{
    echo "false is empty<br/>";
}

if (empty(""))
{
    echo "empty string is empty<br/>";
}
else
{
    echo "empty string is not empty<br/>";
}

if ("")
{
    echo "1";
}
else
{
    echo "2";   // 空字符串返回 false
}

echo "<br />";

// 0 也是 empty 的
empty(0) == TRUE or die("FALSE");

echo "empty PASS";

?>