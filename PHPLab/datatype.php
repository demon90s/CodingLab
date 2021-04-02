<?php
// 字符串
$x = "hello world";
echo $x;
echo "<br>";
$x = 'hi php';
echo $x;
echo "<br>";

// 整数
$x = 5985;
var_dump($x);
echo "<br>";
$x = -345;
var_dump($x);
echo "<br>";
$x = 0x8C;
var_dump($x);
echo "<br>";
$x = 047;	// 八进制数
var_dump($x);	// int(39)
echo "<br>";

// 浮点数
$x = 3.1415;
var_dump($x);
echo "<br>";
$x = -2.11;
var_dump($x);
echo "<br>";
$x = 8E-5;
var_dump($x);	// float(8.0E-5)
echo "<br>";

// 逻辑
$x=true;
$y=false;
var_dump($x);	// bool(true)
echo "<br>";
var_dump($y);
echo "<br>";

// 数组
$cars = array("Volvo", "BMW", "SAAB");
var_dump($cars);
echo "<br>";
echo "My car is {$cars[0]}";	// 得到 Volvo
echo "<br>";

$m = array("a" => "apple", "b" => "banana");
var_dump($m);
echo "<br>";
echo "key a: ", $m["a"];	// 得到 apple
echo "<br>";

// NULL
$x = null;
var_dump($x);	// NULL
echo "<br>";
?>
