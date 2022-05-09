message("            构建: 天宇库源代码 - 文本库")

add_library(dty-text STATIC

    ${CMAKE_CURRENT_LIST_DIR}/src/text.cpp
)

message("            构建-完成")