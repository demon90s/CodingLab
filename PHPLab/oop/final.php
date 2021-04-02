<?

// final 关键字用来组织类被继承，或者方法被重写

final class A
{

}
//class B extends A {} // error

class C
{
    final function foo()
    {

    }
}

class D extends C
{
    //function foo() {} // error
}

?>