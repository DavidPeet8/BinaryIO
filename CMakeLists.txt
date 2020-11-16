cmake_minimum_required(VERSION 3.0.0)

# specify C++ compilation flags
set(CMAKE_CXX_FLAGS "-Wall -MMD -stdlib=libc++")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
# sets PROJECT_NAME variable - name in parentheses
# only in toplevel CMakeLists.txt
project(bmanip)

add_subdirectory(src)
include(CPack)
