message("            构建: 天宇库源代码 - 输入输出库")

add_library(dty-io STATIC

    ${CMAKE_CURRENT_LIST_DIR}/base_stream/ostream.cpp
)

message("            构建-完成")