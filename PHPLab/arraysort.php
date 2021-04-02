<?php
function output($numbers)
{
    foreach ($numbers as $n)
    {
        echo "$n ";
    }
    echo "<br>";
}

function output2($map)
{
    foreach ($map as $k => $v)
    {
        echo "$k=>$v ";
    }
    echo "<br>";
}

$numbers = array(3, 5, 1, 10, 6);

// 从小到大
sort($numbers);
output($numbers);

// 从大到小
rsort($numbers);
output($numbers);

$ages = array("dad"=>30, "mom"=>33, "miemie"=>5);

// 使用值排序，从小到大 arsort 从大到小
asort($ages);
output2($ages);

// 使用键排序，从小到大 krsort 从大到小
ksort($ages);
output2($ages);
?>