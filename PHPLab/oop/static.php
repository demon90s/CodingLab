<?php

class Foo
{
    // static function
    public static function hello()
    {
        echo "Hello PHP<br />";
    }

    // static member
    public static $welcome = "hello world";
}

Foo::hello();

echo Foo::$welcome . "<br />";

?>