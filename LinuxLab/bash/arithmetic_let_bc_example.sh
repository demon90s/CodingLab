#! /bin/bash

# 算术运算

# 整数运算
example1()
{
    local n1=2
    local n2=3

    # 加
    echo $((n1 + n2))               # 5

    # 减
    echo $((n1 - n2))               # -1

    # 乘
    echo $((n1 * n2))               # 6

    # 除
    echo $((n2 / n1))               # 1

    # 取余
    echo $((n2 % n1))               # 1

    # 幂运算
    echo $((n1 ** n2))              # 8

    num=1
    let num=num+20
    echo $num
    let num-=10
    echo $num
}

# 整数运算，使用 $[ expr ] ,与上面的等价
example2()
{
    expr="3 * 4"
    echo "$expr = $[$expr]"
}

# 使用 bc 命令，它支持浮点运算，而上面的只支持简单的整数运算
example3()
{
    # bc -l 将小数点位数设置为20位
    
    local n1=2.5
    local n2=2

    # 加
    echo "$n1 + $n2" | bc -l                   # 4.5

    # 减
    echo "$n1 - $n2" | bc -l                   # 0.5

    # 乘
    echo "$n1 * $n2" | bc -l                   # 5.0

    # 除法
    echo "$n1 / $n2" | bc -l                   # 1.25

    # 幂运算
    echo "$n1 ^ $n2" | bc -l                   # 6.25
}

# 使用 bc 进行进制转换
# obase 表示输出进制
# ibase 表示输入进制, 默认10进制
example4()
{
    number=20
    echo -e "dec 20 -> hex \c"
    echo "obase=16;20" | bc

    echo -e "dec 20 -> bin \c"
    echo "obase=2;20" | bc

    echo -e "hex 14 -> dec \c"
    echo "obase=10;ibase=16;14" | bc
}

main()
{
    #example1
    #example2
    example3
    #example4
}

main