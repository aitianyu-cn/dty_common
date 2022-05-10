set(DTY_NATIVE_TEST_DTY_CORE_NAME ${DTY_NATIVE_TEST_NAME}.dty-core)

message("        构建: " ${DTY_NATIVE_TEST_DTY_CORE_NAME})

message("            执行: " ${DTY_NATIVE_TEST_DTY_CORE_NAME}.core_api)
add_executable(
    ${DTY_NATIVE_TEST_DTY_CORE_NAME}.core_api
    
    core_api.cpp
    
    ${PROJECT_SOURCE_DIR}/native/dty-test-core.cpp
    ${PROJECT_SOURCE_DIR}/native/dty-core.cpp
)

message("            执行: " ${DTY_NATIVE_TEST_DTY_CORE_NAME}.value_to_string)
add_executable(
    ${DTY_NATIVE_TEST_DTY_CORE_NAME}.value_to_string
    
    val2str.cpp
    
    ${PROJECT_SOURCE_DIR}/native/dty-test-core.cpp
    ${PROJECT_SOURCE_DIR}/native/dty-core.cpp
)

message("        构建-完成")