# Utility Library

file(GLOB_RECURSE UTILITY_LIB_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/*.cpp"
)

add_library(utilityLib STATIC ${UTILITY_LIB_SOURCES})

target_include_directories(utilityLib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
