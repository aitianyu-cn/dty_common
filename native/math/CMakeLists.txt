message("            构建: 天宇库源代码 - 数学库")

add_library(dty-math STATIC

    ${CMAKE_CURRENT_LIST_DIR}/base/baseValue.cpp
    ${CMAKE_CURRENT_LIST_DIR}/base/bytesCalc.cpp
    ${CMAKE_CURRENT_LIST_DIR}/base/decimalCalc.cpp

    ${CMAKE_CURRENT_LIST_DIR}/src/biginteger.cpp
)

message("            构建-完成")