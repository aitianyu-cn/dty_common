message("    构建: 天宇库源代码")

add_subdirectory(prime/core ./core)
add_subdirectory(prime ./prime)

add_subdirectory(io ./io)
add_subdirectory(math ./math)
add_subdirectory(model ./model)
add_subdirectory(text ./text)
add_subdirectory(thread ./thread)

message("    构建-完成")