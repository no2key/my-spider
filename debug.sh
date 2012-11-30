#!/usr/bin/sh
# 用途：编译 -> 连接 -> 运行 -> 删除连接
# 使用：./debug.sh

filename=wall-e

gcc -c $filename.c
gcc -l curl $filename.o -o $filename
rm -f $filename.o
./$filename
