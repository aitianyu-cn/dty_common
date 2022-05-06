message("    构建: 天宇本地源代码")

add_subdirectory(prime/core ./lib/core)
add_subdirectory(prime ./lib/prime)

add_subdirectory(io ./lib/io)
add_subdirectory(math ./lib/math)
add_subdirectory(model ./lib/model)
add_subdirectory(text ./lib/text)
add_subdirectory(thread ./lib/thread)

message("    构建-完成")