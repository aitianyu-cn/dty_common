message("            构建: 天宇库源代码 - 基础 - 核心库")

add_library(dty-core STATIC

    ${PROJECT_SOURCE_DIR}/native/dty-core.cpp

    ${CMAKE_CURRENT_LIST_DIR}/src/arghelper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/boolean.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/double.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/error.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/event.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/float.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/formatter.cpp
)

message("            构建-完成")