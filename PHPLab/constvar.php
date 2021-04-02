<?php
// 常量，定义后不能修改
// 使用 define 函数定义常量，第三个参数默认是 false, 表示对大小写敏感
// 使用常量不需要加 $
// 常量是全局的


define ("HELLO", "hello world, hello php");
echo HELLO;
echo "<br>";

function func() {
	echo "func() called, ", HELLO;
	echo "<br>";
}

func();

if (defined("HELLO")) // 需要加上引号
{
	print "HELLO is defined";	// 引号内的常量不会被展开
}
?>
