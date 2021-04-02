<?php

// host:port user password dbname
$link = mysqli_connect("localhost:3306", "root", "123456", "family");

if (!$link)
{
	die("could not connect to mysql: " . mysqli_error());
}

echo "connect to mysql succ<br>";

mysqli_close($link);

?>
