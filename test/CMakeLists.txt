set(DTY_NATIVE_TEST_NAME "dty.common.native.test")

message("    构建: 天宇本地测试代码")

# 准备天宇测试环境基本依赖
message("    加载依赖: " ${DTY_NATIVE_TEST_NAME})
add_library(${DTY_NATIVE_TEST_NAME}.core STATIC

    ${PROJECT_SOURCE_DIR}/native/dty-test-core.cpp
)

# 导入测试程序
add_subdirectory(prime/core ./bin/core)

message("    构建-完成")