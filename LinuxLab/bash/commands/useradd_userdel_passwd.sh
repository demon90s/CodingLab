#! /bin/bash

# useradd 添加用户
# -m 表示添加家目录
f_useradd()
{
    sudo useradd -m test
    ls /home
}

# passwd 设置或修改密码
f_passwd()
{
    sudo passwd test
}

# userdel 删除用户
# -r 表示删除掉家目录
f_userdel()
{
    sudo userdel -r test
    ls /home
}

# 批量修改用户帐号密码的方法
# 使用 chpasswd
# 先创建一个文件 file.txt，以用户名:密码为一对
# test:1234567890
# chapasswd < file.txt

f_main()
{
    f_useradd
    f_passwd
    f_userdel
}

f_main $@