@echo off

chcp 65001

@echo ##################################################################################
@echo #
@echo # 天宇开发者库(Tianyu Developing Library)
@echo # 项目(Project): Tianyu Development library
@echo # 
@echo # 本程序用于构建 天宇开发者库
@echo # Tianyu Developing Library build runner to generate valid lib and header files
@echo # 
@echo ##################################################################################

cd ..

: 开始执行项目构建
@echo.
@echo 开始执行项目构建 (Start to execute CMake)
mkdir build
mkdir target
call cmake . -B ./build -D DTEST=false
@echo 构建完成(Done...)
@echo.
: 开始执行项目构建 - 结束

: 开始生成
@echo.
@echo 开始生成目标文件 (Start to build target files)
cd build
call msbuild "Tianyu Development library.sln" -p:Configuration=Release -m > ..\target\build.log 
@echo 创建完成(Done...)
@echo.
: 开始生成 - 结束

: 开始构建目标头文件
@echo.
@echo 开始生成目标头文件 (Start to build target header files)

cd ..\target
: 在target文件夹中创建头文件文件夹
mkdir header

cd ..

@echo 拷贝核心头文件 (Copy DTY Core header file)
copy .\native\dty-core.hxx .\target\header

@echo 创建静态多语言目录 (Create folder for i18n)
mkdir .\target\header\res
mkdir .\target\header\res\i18n
@echo 拷贝多语言头文件 (Copy i18n header file)
copy .\native\res\i18n\language.h .\target\header\res\i18n

@echo 创建基础核心目录 (Create folder for prime\core)
mkdir .\target\header\prime\core

@echo 创建基础核心 basetype.hpp (Copy basetype.hpp)
copy .\native\prime\core\basetype.hpp .\target\header\prime\core

@echo 创建基础核心 error.hpp (Copy error.hpp)
copy .\native\prime\core\error.hpp .\target\header\prime\core 

@echo 创建基础核心 event.hpp (Copy event.hpp)
copy .\native\prime\core\event.hpp .\target\header\prime\core

@echo 创建基础核心 formatter.hpp (Copy formatter.hpp)
copy .\native\prime\core\formatter.hpp .\target\header\prime\core

@echo 创建基础核心 icollections.hpp (Copy icollections.hpp)
copy .\native\prime\core\icollections.hpp .\target\header\prime\core

@echo 创建基础核心 internal.hpp (Copy internal.hpp)
copy .\native\prime\core\internal.h .\target\header\prime\core

@echo 创建基础核心 iterator.hpp (Copy iterator.hpp)
copy .\native\prime\core\iterator.hpp .\target\header\prime\core

@echo 创建基础核心 pointer.hpp (Copy pointer.hpp)
copy .\native\prime\core\pointer.hpp .\target\header\prime\core

@echo 创建基础核心 property.hpp (Copy property.hpp)
copy .\native\prime\core\property.hpp .\target\header\prime\core

@echo 创建基础组件 core.hxx (Copy core.hxx)
copy .\native\prime\core.hxx .\target\header\prime

@echo 创建基础组件 array.hpp (Copy array.hpp)
copy .\native\prime\array.hpp .\target\header\prime

@echo 开始生成目标头文件 (Done...)

: 开始构建目标头文件 - 结束