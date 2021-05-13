<?php

// str_replace 进行区分大小写的搜索，并替换字符串

$str = "Hello, World";
$str = str_replace("Hello", "Hi", $str);

$str == "Hi, World" or die("FALSE");

echo "str_replace PASS";

?>