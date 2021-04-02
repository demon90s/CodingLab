<?php
// 二维数组：汽车名字，库存
$cars = array(
    array("Volve", 100),
    array("Bmw", 40),
    array("porsche", 10)
);

echo $cars[0][0] . " " . $cars[0][1] . "<br>";

$num = count($cars);
echo "num of cars: " . $num . "<br>";

foreach ($cars as $item) {
    echo "-";
    
    $item_num = count($item);

    for ($i = 0; $i < $item_num; ++$i) {
        echo " " . $item[$i];
    }

    echo "<br>";
}
?>