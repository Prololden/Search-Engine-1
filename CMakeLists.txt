cmake_minimum_required (VERSION 3.8)
project("Search Engine")

set(CMAKE_CXX_STANDARD 20)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(src)