cmake_minimum_required(VERSION 3.18)

###################################################################
# 天宇项目基本信息
###################################################################

# 名称
set(PROJECT_NAME Tianyu_Development_library)
# 版本号
set(PROJECT_VERSION "0.0.0.1" CACHE STRING "Beta")
# 定义项目：使用C++
project(${PROJECT_NAME} LANGUAGES "CXX" VERSION ${PROJECT_VERSION})

###################################################################
# 设置项目编译信息
###################################################################
set(CMAKE_CXX_STANDARD 17)

###################################################################
# 进入项目构建流程
###################################################################
message("开始构建 - 天宇开发者本地库")

# 添加本地源代码库
add_subdirectory(native)

message("")

# 检测并添加测试代码库
if (DEFINED TEST AND ${TEST})
    add_subdirectory(test)
endif ()

message("构建结束 - 天宇开发者本地库")