#! /bin/bash

for file in $(ls *.sh); do
    echo $file
done

# 输出0到9
for (( i = 0; i < 10; i++ )); do
    echo -e "$i \c"
done
echo ""

# 输出A到Z
for v in {A..Z}; do
    echo -e "$v \c"
done
echo ""