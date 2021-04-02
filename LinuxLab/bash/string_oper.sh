#! /bin/bash

# 变量定义/引用
FOO="Hello"
echo $FOO

# 追加
FOO+=" World"
echo ${FOO}

# 求字符串长度
FOO="fuck"
echo ${#FOO}

# 提取子串（字符串:位置:长度）
FOO="hello wolrd"
echo ${FOO:0:5}
echo ${FOO:6}       # world

# 头删最短子串
FOO="hello world hello world"
echo ${FOO#*hello}

# 头删最长子串
echo ${FOO##*hello}

# 尾删最短子串
echo ${FOO%world*}

# 尾删最长子串
echo ${FOO%%world*}

# 替换第一个内容
echo ${FOO/hello/hi}

# 替换所有内容
echo ${FOO//hello/hi}