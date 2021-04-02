# 创建一个硬链接，如果存在则失败

ln foo foo_ln

# 强制创建一个硬链接
# 修改硬链接同时也会把原文件的内容修改了（还是共享的文件内容）

ln -f foo foo_ln

# 创建一个软链接 foo_symbol_ln 。如果链接存在，则会有错误提示，加-f去掉。

ln -s foo foo_symbol_ln