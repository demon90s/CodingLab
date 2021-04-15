<?php

$dir = "testdir";

$ret = mkdir($dir);
if (!$ret)
{
    echo "mkdir failed!";
}

?>