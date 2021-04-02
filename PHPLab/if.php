<?php
$t = date("H");

/*
var_dump($t); // string
echo "<br>";
*/

if ($t < "10") {
	echo "Have a good morning";
}
elseif ($t < "20") {
	echo "Have a good day";
}
else {
	echo "Have a good night";
}
?>
