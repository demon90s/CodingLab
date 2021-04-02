<?php
$cars = array("porsche", "BMW", "Volvo");
$cars[3] = "T";

echo $cars[0] . "<br>";

echo count($cars) . "<br>";     // 4

$len = count($cars);
for ($i = 0; $i < $len; $i++)
{
    echo $i . ": " . $cars[$i] . "<br>";
}

foreach ($cars as $item)
{
    echo $item . "<br>";
}

// 关联数组
$age = array("baba" => 30, "mama" => 33);
$age["miemie"] = 5;

foreach ($age as $k => $v)
{
    echo $k . " is " . $v . " years old<br>";
}

?>