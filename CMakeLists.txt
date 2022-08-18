cmake_minimum_required (VERSION 3.8)

project ("Search Engine")

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable (SerachEngine "Search Engine.cpp" "Search Engine.h" "inc/ConverterJSON.cpp")

target_link_libraries(SerachEngine PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SerachEngine PROPERTY CXX_STANDARD 20)
endif()