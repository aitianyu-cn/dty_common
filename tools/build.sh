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
command $(cmake . -B ./build -D DTEST=false)
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

# 开始构建目标头文件
print ""
print "开始生成目标头文件 (Start to build target header files)"

cd ../target
# 在target文件夹中创建头文件文件夹
mkdir header

cd ..

print "拷贝核心头文件 (Copy DTY Core header file)"
cp ./native/dty-core.hxx ./target/header

print "创建静态多语言目录 (Create folder for i18n)"
mkdir ./target/header/res
mkdir ./target/header/res/i18n
print "拷贝多语言头文件 (Copy i18n header file)"
cp ./native/res/i18n/language.h ./target/header/res/i18n

print "创建基础核心目录 (Create folder for prime/core)"
mkdir ./target/header/prime/core

print "创建基础核心 basetype.hpp (Copy basetype.hpp)"
cp ./native/prime/core/basetype.hpp ./target/header/prime/core

print "创建基础核心 error.hpp (Copy error.hpp)"
cp ./native/prime/core/error.hpp ./target/header/prime/core 

print "创建基础核心 event.hpp (Copy event.hpp)"
cp ./native/prime/core/event.hpp ./target/header/prime/core

print "创建基础核心 formatter.hpp (Copy formatter.hpp)"
cp ./native/prime/core/formatter.hpp ./target/header/prime/core

print "创建基础核心 icollections.hpp (Copy icollections.hpp)"
cp ./native/prime/core/icollections.hpp ./target/header/prime/core

print "创建基础核心 internal.hpp (Copy internal.hpp)"
cp ./native/prime/core/internal.h ./target/header/prime/core

print "创建基础核心 iterator.hpp (Copy iterator.hpp)"
cp ./native/prime/core/iterator.hpp ./target/header/prime/core

print "创建基础核心 pointer.hpp (Copy pointer.hpp)"
cp ./native/prime/core/pointer.hpp ./target/header/prime/core

print 创"建基础核心 property.hpp (Copy property.hpp)"
cp ./native/prime/core/property.hpp ./target/header/prime/core

print "开始生成目标头文件 (Done...)"
