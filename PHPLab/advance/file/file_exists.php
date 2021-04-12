<?php

$test_file = "../../../../phplab_file/sometext.txt";

if (file_exists($test_file))
{
    echo "$test_file exist";
}
else
{
    echo "$test_file is not exist";
}

?>