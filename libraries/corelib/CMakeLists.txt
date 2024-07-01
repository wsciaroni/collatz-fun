# CORE Library

file(GLOB_RECURSE CORE_LIB_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/*.cpp"
)

add_library(coreLib STATIC ${CORE_LIB_SOURCES})

target_include_directories(coreLib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

target_link_libraries(coreLib PUBLIC utilityLib)