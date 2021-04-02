<?php

class Goodbye
{
    const MESSAGE = "Thank you for visting.";

    // self 关键字
    function bye()
    {
        echo self::MESSAGE;
    }
}

echo Goodbye::MESSAGE . "<br />";

$goodbye = new Goodbye();
$goodbye->bye();
echo "<br />";

?>