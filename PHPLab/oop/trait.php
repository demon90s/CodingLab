<?php

// 可以把 trait 的内容共享给 class ，从而减少重复代码

trait message1
{
    public function msg1()
    {
        echo "message1";
    }
}

trait message2
{
    public function msg2()
    {
        echo "message2";
    }
}

class Foo
{
    use message1;
    use message2;
}

$foo = new Foo();
$foo->msg1();
echo "<br />";

$foo->msg2();
echo "<br />";

?>