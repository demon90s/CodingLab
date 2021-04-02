<?
// mktime(hour, minute, second, month, day, year)
// 返回时间戳

date_default_timezone_set("Asia/Shanghai");

// 默认取得当前时间戳
$timestamp = mktime();
echo "current timestamp: " . $timestamp . "<br>";

$d = date("Y-m-d H:i:s", $timestamp);
echo "date: " . $d . "<br>";

$timestamp += 10;
$d = date("Y-m-d H:i:s", $timestamp);
echo "date: " . $d . "<br>";

?>