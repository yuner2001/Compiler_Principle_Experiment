cmake_minimum_required(VERSION 3.10)
project(GrammarClassifier)

include(CTest)
enable_testing()


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
file(GLOB SRC_LIST "*.cpp" "src/*.cpp")
add_executable(GrammarClassifier ${SRC_LIST})

