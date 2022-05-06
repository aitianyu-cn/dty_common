cmake_minimum_required(VERSION 3.18)

###################################################################
# 天宇项目基本信息
###################################################################

# 名称
set(PROJECT_NAME "Tianyu Development library")
# 版本号
set(PROJECT_VERSION "0.0.1")
# 定义项目：使用C++
project(${PROJECT_NAME} LANGUAGES "CXX" VERSION ${PROJECT_VERSION})

###################################################################
# 设置项目编译信息
###################################################################
set(CMAKE_CXX_STANDARD 17)

# 为Microsoft Visual Studio设置编译选项
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " /Zc:__cplusplus")
endif()

set(DTY_PROJECT_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
# 设置通用输出目录
set(EXECUTABLE_OUTPUT_PATH ${DTY_PROJECT_OUTPUT_PATH}/bin)
set(LIBRARY_OUTPUT_PATH ${DTY_PROJECT_OUTPUT_PATH}/lib)
# 设置Microsoft Visual Studio可用的输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/bin)

# 设置开发状态
if (DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL Dev)
    ADD_DEFINITIONS(-D__DTY_DEV_MODE__)
endif ()

###################################################################
# 进入项目构建流程
###################################################################
message("天宇开发者库")
message("项目：" ${PROJECT_NAME})
message("版本：" ${PROJECT_VERSION})
message("")

message("开始构建 - 天宇开发者库")

# 添加本地源代码库
add_subdirectory(native)

message("")

# 检测并添加测试代码库
if (DEFINED DTEST AND ${DTEST})
    add_subdirectory(test)
endif ()

message("构建结束 - 天宇开发者库")