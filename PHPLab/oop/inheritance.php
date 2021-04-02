<?php

// php 只支持单继承

class Fruit
{
    protected $name;
    protected $color;

    function __construct($name, $color)
    {
        $this->name = $name;
        $this->color = $color;
    }
}

class Apple extends Fruit
{
    function message()
    {
        echo "I am " . $this->name . " color: " . $this->color;
    }
}

$apple = new Apple("Apple", "Red");
echo $apple->message();
echo "<br />";

?>