#! /bin/bash

# df 输出磁盘占用情况
# -h 表示友好的输出
f_test_df()
{
	df -h
}

# du 输出文件夹的占用情况
# -h 表示友好的输出
# --max-depth=N 表示输出层级
f_test_du()
{
	du -h --max-depth=1 ..
}

# du -s 可以输出目标总占用空间
f_test_du2()
{
	# 输出当前目录所占用的空间
	du -sh .
}

f_main()
{
	#f_test_df
	#f_test_du
	f_test_du2
}

f_main $@
