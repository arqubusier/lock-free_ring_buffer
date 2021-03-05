add_executable(
	ring_test
	${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ring_test.cpp
)
add_test(NAME all_tests COMMAND ring_test)

target_include_directories (
    ring_test
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

# Link against Google Test library
target_link_libraries(ring_test gmock_main)
