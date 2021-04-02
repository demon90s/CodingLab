<?php

abstract class Fruit
{
    protected $name;

    public function __construct($name)
    {
        $this->name = $name;
    }

    abstract public function info();
}

class Apple extends Fruit
{
    public function info()
    {
        echo "I am " . $this->name;
    }
}

$apple = new Apple("Apple");
$apple->info();
echo "<br />";

?>