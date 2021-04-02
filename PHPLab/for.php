<?php
for ($x = 1; $x <= 5; $x++) {
	echo "x = $x<br>";
}

// foreach 只适用于数组
$colors = array("red", "green", "blue", "yellow");

foreach ($colors as $v) {
	echo "$v<br>";
}
?>
