<?php
// $GLOBALS允许在PHP脚本中的任意位置访问全局变量
// PHP $GLOBALS 数组里存储了所有全局变量，变量的名字就是数组的键

$x = 3;
$y = 4;

function sumxy() {
    $GLOBALS['z'] = $GLOBALS['x'] + $GLOBALS['y'];
}

sumxy();
echo $z;    // sumxy函数中定义了一个全局变量z
?>