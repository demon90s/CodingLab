<?php

// 设置时区
date_default_timezone_set("Asia/Shanghai");

// 查询时区
// https://www.php.net/timezones

/*
d 表示天 01-31
m 表示月 01-12
Y 表示年
H 24小时制小时(00-23)
i 分钟(00-59)
s 秒(00-59)
l 周几的字符串描述
*/

$cur_hour = date("H");
$cur_min = date("i");
$cur_sec = date("s");
$cur_year = date("Y");
$cur_mon = date("m");
$cur_day = date("d");

echo "cur_hour: " . $cur_hour . "<br>";
echo "cur_min: " . $cur_min . "<br>";
echo "cur_sec: " . $cur_sec . "<br>";
echo "cur_year: " . $cur_year . "<br>";
echo "cur_mon: " . $cur_mon . "<br>";
echo "cur_day: " . $cur_day . "<br>";

$ymd = date("Y-m-d H:i:s l");
echo "now is: " . $ymd . "<br>";

// 第二个参数可以是一个时间戳
$ymd = date("Y-m-d H:i:s l", 0);
echo "unix time begin: " . $ymd . "<br>";
?>

<!-- 自动版权年份 -->
@2019-<?php echo date("Y"); ?><br>