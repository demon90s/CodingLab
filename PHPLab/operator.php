<?php
// 算术运算
$x = 3;
$y = 4;
echo ($x + $y);		// 25
echo "<br>";
echo $x - $y;		// -1
echo "<br>";
echo $x * $y;		// 12
echo "<br>";
echo $x / $y;		// 0.75
echo "<br>";
echo $y % $x;		// 1
echo "<br>";

$z = $x;
$z += $y;
echo $z;		// 7
echo "<br>";

echo $z++;		// 7
echo "<br>";

// z now is 8
++$z;
echo $z;		// 9
echo "<br>";

// . 字符串串接
$a = "hello";
$b = $a . " world";
echo $b;		// hello world
echo "<br>";

$a .= " php";
echo $a;		// hello php
echo "<br>";

// 比较运算符
echo "<h2>测试比较运算符</h2>";
$x = 17;
$y = "17";

var_dump($x == $y);	// true
echo "<br>";

// 全等，完全相同，即类型也要相同
var_dump($x === $y);	// false
echo "<br>";

// 或者用 <> 运算符
var_dump($x != $y);	// false
echo "<br>";

// 不全等 $x 不等于 $y ，或者他们类型不相同
var_dump($x !== $y);	// true
echo "<br>";

$a = 17;
$b = 8;

var_dump($a > $b);	// true
echo "<br>";

$b = 17;
var_dump($a >= $b);	// true
echo "<br>";

// 逻辑运算符
// 与 and &&
// 或 or ||
// 异或 xor
// 非 !

// 数组运算符
echo "<h2>测试数组运算符</h2>";
$x = array("a" => "apple", "b" => "banana");
$y = array("c" => "orange", "d" => "peach");

// + 联合 不覆盖重复的键，也就是如果x有一个key，y也有，那么忽略掉y的 key-value
$z = $x + $y;
var_dump($z);
echo "<br>";

// == 相等，拥有相同的 key-value
var_dump($x == $y);
echo "<br>";

// === 全等，相同 key-value ，且顺序相同，类型相同
// != 不相等
// !== 不全等
?>
