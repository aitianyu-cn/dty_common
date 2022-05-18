@echo off

chcp 65001

@echo ##################################################################################
@echo #
@echo # 天宇开发者库(Tianyu Developing Library)
@echo # 项目(Project): Tianyu Development library
@echo # 
@echo # 本程序用于构建 天宇开发者库与测试程序
@echo # Tianyu Developing Library build runner to generate valid lib and tests
@echo # 
@echo # 
@echo ##################################################################################

cd ..

: 开始执行项目构建
@echo.
@echo 开始执行项目构建 (Start to execute CMake)
mkdir build
mkdir target
call cmake . -B ./build -D DTEST=true
@echo 构建完成(Done...)
@echo.
: 开始执行项目构建 - 结束

: 开始生成
@echo.
@echo 开始生成目标文件 (Start to build target files)
cd build
call msbuild "Tianyu Development library.sln" -p:Configuration=Release -m > ..\target\build-test.log 
@echo 创建完成(Done...)
@echo.
: 开始生成 - 结束