message("            构建: 天宇本地源代码 - 基础库")

add_library(dty-prime STATIC

    ${CMAKE_CURRENT_LIST_DIR}/src/bitmap.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/console.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/guid.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/math.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mathf.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/string.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/system.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/version.cpp

    ${CMAKE_CURRENT_LIST_DIR}/src/time/datetime.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/time/time.format.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/time/time.now.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/time/time.parse.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/time/times.helper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/time/timespan.cpp
)

message("            构建-完成")