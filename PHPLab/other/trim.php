<?php

// trim 函数去掉首位的空白字符(制表符，空格，换行)

$str = "\n\t hello \n\t    ";
$trim_str = trim($str);

$trim_str == "hello" or die("FAIL");

echo "trim PASS";

?>