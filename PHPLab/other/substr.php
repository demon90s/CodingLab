<?php

// substr 从字符串中提取子字符串

$str = "hello, world";

$sub = substr($str, 0, 5);	// 从位置0开始提取5个字符串
$sub == "hello" or die("FAIL");

// 第二个参数可以省略掉，那么会取到结尾
$sub = substr($str, 7);
$sub == "world" or die("FAIL");

// 起始位置可以是负数，表示从末尾开始第几个字符
$sub = substr($str, -5);
$sub == "world" or die("FAIL");

print "PASS";

?>