<?php

class Fruit
{
    protected $name;

    function __construct($name)
    {
        $this->name = $name;
    }

    function info()
    {
        echo "I am fruit with name: " . $this->name;
    }
}

class Apple extends Fruit
{
    protected $color;

    function __construct($name, $color)
    {
        $this->name = $name;
        $this->color = $color;
    }

    function info()
    {
        echo "I am Apple with name: " . $this->name . " color: " . $this->color;
    }
}

$apple = new Apple("apple", "red");
$apple->info();
echo "<br />";

?>