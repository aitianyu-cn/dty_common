set(DTY_NATIVE_TEST_PRIME_NAME ${DTY_NATIVE_TEST_NAME}.prime)

message("        构建: " ${DTY_NATIVE_TEST_PRIME_NAME})

# 导入测试程序
add_subdirectory(core ./core)

message("        构建-完成")