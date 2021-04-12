<?php
function sayhi()
{
    echo "hello world<br>";
}

function sayhi_with_param($param)
{
    echo "hi, $param<br>";
}

function add($x, $y)
{
    $ret = $x + $y;
    echo $ret;
    echo "<br>";
    return $ret;
}

function say_hi_with_default_param($param="param")
{
    echo "hi, $param<br>";
}

// test global
$g_foo = 0;
function test_global()
{
    global $g_foo;

    ++$g_foo;
}
echo "g_foo is: $g_foo" . '<br />';    // 0
test_global();
echo "g_foo is: $g_foo" . '<br />';    // 1

sayhi();
sayhi_with_param("php");
$sum = add(3, 4);
echo "sum = $sum<br>";
say_hi_with_default_param("php");
say_hi_with_default_param();
?>