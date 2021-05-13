<?php

// is_numeric 判断变量是否是一个有效的数字

$var1 = 2309;
$var2 = '80.23';
$var3 = 'Bears';

is_numeric($var1) == TRUE or die("FAIL");
is_numeric($var2) == TRUE or die("FAIL");
is_numeric($var3) == FALSE or die("FAIL");

echo "is_numeric PASS"; 

?>