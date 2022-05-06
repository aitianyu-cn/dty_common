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

set(DTY_PROJECT_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DTY_PROJECT_OUTPUT_PATH}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DTY_PROJECT_OUTPUT_PATH}/bin)

if (DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-D__DTY_DEV_MODE__)
endif ()

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