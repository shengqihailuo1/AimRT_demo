cmake_minimum_required(VERSION 3.24)

project(helloworld LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/GetAimRT.cmake)

add_subdirectory(src)
