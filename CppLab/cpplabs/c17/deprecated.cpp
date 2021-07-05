// deprecated 注解，告诉编译器表示一个函数或类型已经弃用，如果使用，编译器将发出警告

//[[deprecated]] void funcx()
[[deprecated("use funcy instead")]] void funcx() // 可以加上一句提示
{

}

int main()
{
    funcx();
}