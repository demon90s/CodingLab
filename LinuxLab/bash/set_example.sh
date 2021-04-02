#! /bin/bash

# set为shell设置了参数变量
# set还可以设置一些shell功能

test1()
{
    # 设置函数的参数（即$1 $2 ...）
    set hello world

    echo $0     # 第一个参数没有改变，还是程序名字
    echo $1     # hello
    echo $2     # world
}

# set -o/+o
# -o 表示采用对应设置, +o 表示取消对应设置
test2()
{
    # nounset 表示不能使用未定义的变量，否则输出错误并退出, 且返回值非0
    # set -u 一样和这个命令等价, set +u 恢复原先的设定
    set -o nounset
    #NOSET_VAR=hi
    echo $NOSET_VAR
    echo "Normal return"
}

test3()
{
    # noclobber 表示不能重定向一个已存在的文件, 否则输出错误信息, 程序继续执行
    set -o noclobber
    echo "haha" > ./date.sh
    echo "Normal return"
}

test_xtrace()
{
    # xtrace 表示将输出脚本实际执行的内容
    # 同 set -x
    set -o xtrace

    HELLO="hello world"
    echo $HELLO

    set +o xtrace
}

test_errexit()
{
    # Exit immediately if a command exits with a non-zero status.
    # 同 set -e

    set -o errexit

    #rm -f /usr/bin/

    set +o errexit

    echo "Normal return"
}

main()
{
    test1
    #test2
    test3

    echo "===test_xtrace begin==="
    test_xtrace
    echo "===test xtrace end==="

    echo "===test_errexit begin==="
    test_errexit
    echo "===test_errexit end==="
}

main
