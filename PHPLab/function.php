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

sayhi();
sayhi_with_param("php");
$sum = add(3, 4);
echo "sum = $sum<br>";
say_hi_with_default_param("php");
say_hi_with_default_param();
?>