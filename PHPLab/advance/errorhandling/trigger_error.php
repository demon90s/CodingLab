<?php

$test = 2;

if ($test > 1) {
	//trigger_error("Value must <= 1"); // default, NOTICE
	trigger_error("Value must <= 1", E_USER_WARNING); // warning will not stop scripts
	//trigger_error("Value must <= 1", E_USER_ERROR); // this error_level will stop scripts
}

echo "end";

?>
