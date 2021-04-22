cmake_minimum_required(VERSION 3.8)
project(DotProductVisualization)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/dev/libs/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics window system network audio REQUIRED)

add_executable(${PROJECT_NAME} 
	src/main.cpp
    src/calc.cpp
)

target_link_libraries(${PROJECT_NAME}
	sfml-graphics
	sfml-window
	sfml-system
	sfml-network
	sfml-audio
)
