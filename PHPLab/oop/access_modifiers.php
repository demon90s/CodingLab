<?php

// public: 随处可访问，默认的
// protected: 仅class内或者派生类可访问
// private: 仅class内可访问

class Fruit
{
    public $name;
    protected $color;
    private $weight;

    function set_name($n)
    {
        $this->name = $n;
    }
    protected function set_color($c)
    {
        $this->color = $c;
    }
}

$mango = new Fruit();
$mango->name = "Mango";       // OK
//$mango->color = "Yellow";       // Error
//$mango->weight = 10;        // Error

$mango->set_name("Mango");  //OK
//$mango->set_color("Yello"); // Error
?>
