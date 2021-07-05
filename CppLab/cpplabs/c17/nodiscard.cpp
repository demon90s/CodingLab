// nodiscard 注解告诉编译器，函数的返回值不可以丢弃，否则将发出警告

[[nodiscard]]
int *get_resource()
{
    return nullptr;
}

int main()
{
    get_resource();
}