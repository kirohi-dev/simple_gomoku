cmake_minimum_required(VERSION 3.2)
project(pybind_test VERSION 0.1.0)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# pybind11をCMakeListsの探査範囲に追加
add_subdirectory(extern/pybind11)

add_library(test lib.cpp)

# 対象をpythonにbindする
pybind11_add_module(mymodule mymodule.cpp)
# liblaryをリンクする
target_link_libraries(mymodule PRIVATE test)



add_executable(main main.cpp)

target_link_libraries(main PRIVATE test)
