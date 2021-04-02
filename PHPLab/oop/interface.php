<?php

// interface 不可以有成员变量
// 只能有一个无实现的public method

interface Animal
{
    public function makesound();
}

class Cat implements Animal
{
    public function makesound()
    {
        echo "[[Meow]]";
    }
}

$cat = new Cat();
$cat->makesound();
echo "<br />";

?>