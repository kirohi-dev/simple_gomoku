set(CMAKE_CXX_STANDARD 17)

# pybind11をCMakeListsの探査範囲に追加
add_subdirectory(../../extern/pybind11 extern/pybind11)

add_library(gomoku STATIC
  gomoku.cpp
  stone.cpp
  error.cpp
)

# 対象をpythonにbindする
pybind11_add_module(gomoku_lib
  lib.cpp
)

target_link_libraries(gomoku_lib PRIVATE gomoku)

# set shared object file name
set_target_properties(gomoku_lib PROPERTIES PREFIX "")
set_target_properties(gomoku_lib PROPERTIES OUTPUT_NAME "gomoku_engine")
set_target_properties(gomoku_lib PROPERTIES SUFFIX ".so")

# set output destination
IF(EXISTS "${PROJECT_SOURCE_DIR}/.venv")
  set_target_properties(gomoku_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/.venv/lib/python3.9/site-packages"
  )
ELSE()
  message( SEND_ERROR "please create venv on your project with the name .venv")
ENDIF()

# generate stub
IF(EXISTS "${PROJECT_SOURCE_DIR}/.venv/lib/python3.9/site-packages/pybind11_stubgen")
  add_custom_command(TARGET gomoku_lib
    POST_BUILD
    COMMAND pipenv run stubgen
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
  )
ELSE()
  message( SEND_ERROR "please install pipenv dipendency")
ENDIF()

add_executable(gomoku_exe ex.cpp)

target_link_libraries(gomoku_exe PRIVATE
  gomoku
)
