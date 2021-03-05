cmake_minimum_required (VERSION 3.10.0)
cmake_policy(VERSION 3.10.0)

project(lock-free_ring_buffer VERSION 0.1)
#set(VERSION 0.1)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(
	ring
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.cpp
)

target_include_directories (
    ring
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)
    add_subdirectory (test)
endif()
