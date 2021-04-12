<?php

$test_file = "../../../phplab_file/sometext.txt";

if (touch($test_file))
{
    echo "touch $test_file succ";
}
else
{
    echo "touch $test_file fail";
}

?>