cmake_minimum_required(VERSION 2.8.4)
project(sub_set CXX)

set(WARNINGS_FLAGS "-pedantic -Werror -Wall -Wextra -Wshadow -Wfloat-equal -Wformat=2 -O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS_FLAGS} -std=c++14")

#find_package(tbb REQUIRED)

file(GLOB_RECURSE
    source_files
    source/*
)

add_executable(sub_set ${source_files})

target_link_libraries(sub_set tbb)
