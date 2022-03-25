file(GLOB_RECURSE SRCS "./src/*.cpp" "./src/*.c")
file(GLOB_RECURSE HEADERS "./src/*.hpp" "./src/*.h")
add_executable(Compiler ${SRCS} ${HEADERS})
add_custom_command(TARGET Compiler POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/res"
    ${CMAKE_CURRENT_BINARY_DIR}"/res"
)