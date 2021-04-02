<?php

// host:port user password dbname
$link = mysqli_connect("localhost:3306", "root", "123456", "family");

if (!$link)
{
	die("could not connect to mysql: " . mysqli_error());
}

echo "connect to mysql succ<br>";

// delete table
mysqli_query($link, "DELETE FROM member");

// insert
$ret = mysqli_query($link, "INSERT INTO member(name, age) VALUES ('diwen', '30')");
if ($ret)
{
	echo "add one record<br>";
}

// select
$result = mysqli_query($link, "SELECT * FROM member");
while ($row = mysqli_fetch_array($result))
{
	echo $row['name'] . " " . $row['age'];
	echo "<br>";
}

mysqli_close($link);

?>
