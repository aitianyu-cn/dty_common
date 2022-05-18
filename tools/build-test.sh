#!/bin/bash
# Tianyu Native Init Runner

function print()
{
    echo "$1"
    return
}

print "##################################################################################"
print "#"
print "# 天宇开发者库(Tianyu Developing Library)"
print "# 项目(Project)# Tianyu Development library"
print "# "
print "# 本程序用于构建 天宇开发者库"
print "# Tianyu Developing Library build runner to generate valid lib and header files"
print "# "
print "##################################################################################"

cd ..

# 开始执行项目构建
print ""
print "开始执行项目构建 (Start to execute CMake)"
mkdir build
mkdir target
command $(cmake ./ -B ./build -D DTEST=true)
print "构建完成(Done...)"
print ""
# 开始执行项目构建 - 结束

# 开始生成
print ""
print "开始生成目标文件 (Start to build target files)"
cd build
command $(make -i 2>../target/error.log >../target/build.log)
print "创建完成(Done...)"
print ""
# 开始生成 - 结束