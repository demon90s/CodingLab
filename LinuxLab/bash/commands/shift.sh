#! /bin/bash

# shift
# 左移参数，默认移动一位
# 被移动掉的，不可恢复，最多移动到 $1

set -e

test_shift()
{
    count=0
    while [ -n "$1" ]; do
        count=$((count + 1))

        echo "parameter $count is: $1"
        shift 1
    done
}

test_shift a b c