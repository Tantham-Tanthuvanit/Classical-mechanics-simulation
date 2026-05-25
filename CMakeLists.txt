CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cms)

find_package(raylib REQUIRED)

add_executable(cms
	src/main.cpp
	src/simulation.cpp
)

target_link_libraries(cms
	raylib
)
