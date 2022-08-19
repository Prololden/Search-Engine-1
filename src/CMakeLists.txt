cmake_minimum_required (VERSION 3.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(Src
	ConverterJSON.cpp
	SearchEngine.cpp
	main.cpp
)

add_executable(SearchEngine ${Src})

target_link_libraries(SearchEngine nlohmann_json::nlohmann_json)
target_include_directories(SearchEngine PUBLIC ${MY_INCLUDE_DIR})