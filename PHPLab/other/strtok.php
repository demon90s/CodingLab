<?php

// strtok 使用一个预定的分隔符作为标记，从大字符串中创建子字符串

$name = "liu diwen";
$first = strtok($name, ' ');

$first == "liu" OR die("FAIL");

echo "PASS";

?>