<?php

if (!file_exists("noexistfile")) {
	//die("file not found"); // stop script with message

	// or die() with message
	echo "file not found";
	die();
}

echo "never run here!";

?>
