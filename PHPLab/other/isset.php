<?php

// isset 当变量有值（包括0、FALSE或者空字符串） isset 返回TRUE，否则返回FALSE

$var1 = 0;
$var2 = 'something';
$var3 = '';

isset($var) == FALSE or die("FALSE");
isset($var1) == TRUE or die("FALSE");
isset($var2) == TRUE or die("FALSE");
isset($var3) == TRUE or die("FALSE");

echo "isset PASS";

?>