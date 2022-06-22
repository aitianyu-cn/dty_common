set(DTY_NATIVE_TEST_PRIME_NAME ${DTY_NATIVE_TEST_NAME}.prime)

message("        构建: " ${DTY_NATIVE_TEST_PRIME_NAME})

# 导入测试程序
add_subdirectory(core ./core)

# 构建测试 - dty.common.native.test.prime.array
message("           执行: " ${DTY_NATIVE_TEST_PRIME_NAME}.array)
add_executable(${DTY_NATIVE_TEST_PRIME_NAME}.array array.cpp)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_NAME}.array

    dty-core
    ${DTY_NATIVE_TEST_NAME}.core
)

message("        构建-完成")