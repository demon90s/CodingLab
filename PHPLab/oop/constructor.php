<?php

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

// bool(true)
var_dump($apple instanceof Fruit);

?>