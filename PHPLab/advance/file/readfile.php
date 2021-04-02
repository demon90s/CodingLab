<?php

// readfile 读取文件并写到输出流，返回文件字节数

$numbytes = readfile("sometext.txt");

echo "<br>";
echo $numbytes;

?>