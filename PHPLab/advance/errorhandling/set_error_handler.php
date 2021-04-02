<?php

function custom_error($errno, $errstr)
{
	echo "<b>Error:</b>[$errno] $errstr<br>";
	echo "Ending Script";
	die();
}

set_error_handler("custom_error", E_USER_WARNING);	// handling for WARNING

trigger_error("Some error Triggered", E_USER_WARNING);

?>
