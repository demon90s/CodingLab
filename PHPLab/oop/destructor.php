<?php

// destructor 会在脚本结束时调用

class Fruit
{
    // Properties
    public $name;
    public $color;

    // constructor
    function __construct($name, $color)
    {
        $this->name = $name;
        $this->color = $color;
    }

    // destructor
    function __destruct()
    {
        echo "The fruit " . $this->name . " destruct.<br \>";
    }

    // Methods
    function get_name()
    {
        return $this->name;
    }
    function get_color()
    {
        return $this->color;
    }
}

// define an object with constructor
$apple = new Fruit("Apple", "Red");
echo "Name: " . $apple->get_name();
echo "<br />";
echo "Color: " . $apple->get_color();
echo "<br />";

?>