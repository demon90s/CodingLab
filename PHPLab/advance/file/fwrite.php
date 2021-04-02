<?php

$file = fopen("tmp.txt", "w") or die("can not open file");

fwrite($file, $txt);

fclose($file);

?>