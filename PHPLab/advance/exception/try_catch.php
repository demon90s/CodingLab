<?php

function check($num) {
	if ($num == 0) {
		throw new Exception("num must not be 0");
	}
}

echo "begin" . "<br>";

try {
	check(0);
} catch (Exception $e) {
	echo "Catch exception with message: " . $e->getMessage() . "<br>";
}

echo "end<br>";

?>
