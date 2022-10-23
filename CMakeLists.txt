cmake_minimum_required(VERSION 3.23)

project(enum_macros)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXEC src/demo.cpp)

add_executable(demo ${EXEC})
