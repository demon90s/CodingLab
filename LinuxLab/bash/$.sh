#! /bin/bash

set -ex

# 重置脚本参数
set param1 param2 hello world

# $0 脚本的名字
echo $0

# $# 传递给脚本的参数个数（不包含脚本本身，没有参数就是0）
(($# == 4))

# $1 $2 ... 脚本第1个参数，第二个。。。
(($1 == "param1")) && (($2 == "param2")) && (($3 == "hello")) && (($4 == "world"))

# $$ 脚本的进程ID
echo "PID: $$"

# $! 脚本中上一个执行的进程pid（进程需要存在）
sleep 3&
echo "last command pid: $!"

# $@ 所有参数，不包括脚本本身
echo "all param: $@"

# $? 上一个命令的执行返回码
echo "last command return value: $?"

echo "[TEST] \$ PASS"