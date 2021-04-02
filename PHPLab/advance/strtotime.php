<?php

// strtotime(time, now) 使用字符串来创建日期，返回一个unix时间

/*
1 January
2 February
3 March
4 April
5 May
6 June
7 July
8 August
9 September
10 October
11 November
12 December
*/


$d = strtotime("10:38pm April 15 2015");
echo "创建的日期是 " . date("Y-m-d h:i:sa", $d) . "<br>";

$nowdate = date("Y-m-d H:i:s");
echo "now date: " . $nowdate . "<br>";

// 明天零点时间
$d = strtotime("tomorrow");
echo "tomorrow date: " . date("Y-m-d H:i:s", $d) . "<br>";

// 下一个星期六的零点
$d = strtotime("next Saturday");
echo "next Saturday date: " . date("Y-m-d H:i:s", $d) . "<br>";

// 当前时间+三天
$d = strtotime("+3 Days");
echo "after 3 days date: " . date("Y-m-d H:i:s", $d) . "<br>";

?>
