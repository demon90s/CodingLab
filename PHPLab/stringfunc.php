<?php
// 参考：https://www.w3school.com.cn/php/php_ref_string.asp

// strlen
echo strlen("hello world");	// 11
echo "<br>";

$x = "hello world";
echo strlen($x);		// 11
echo "<br>";

// str_word_count
echo str_word_count("hello world!");	// 2
echo "<br>";

// 反转字符串
// strrev
echo strrev("hello");	// olleh
echo "<br>";

// strpos
echo strpos("hello world", "world");	// 6 找到，下标从0开始
echo "<br>";
$x = strpos("hello world", "warld");	// false 找不到返回false
var_dump($x);
echo "<br>";

// str_replace
echo str_replace("hello", "hi", "hello world"); // hi world
echo "<br>"
?>
