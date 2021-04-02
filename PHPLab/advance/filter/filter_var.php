<?php

$i = 123;

if (filter_var($i, FILTER_VALIDATE_INT)) {
	echo "i($i) is valid integer<br>";
}
else {
	echo "i($i) is not valid integer<br>";
}

// with option
$int_options = array
(
	"options" => array
	(
		"min_range" => 0,
		"max_range" => 256
	)
);

$i = 300;
if (filter_var($i, FILTER_VALIDATE_INT, $int_options))
{
	echo "i($i) is valid integer(0, 256)<br>";
}
else
{
	echo "i($i) is not valid integer(0, 256)<br>";
}

?>
