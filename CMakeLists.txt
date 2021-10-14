cmake_minimum_required(VERSION 3.16)
project(convexHull)

set(CMAKE_CXX_STANDARD 11)

SET(MYCOMPILE_FLAGS "-g")

# target_compile_options(convexHull ${MYCOMPILE_FLAGS})
add_definitions(${MYCOMPILE_FLAGS})

include_directories(./inc ./src ./)

add_executable(convexHull
		./inc/ConvexHull.hpp
		./inc/Point.hpp

		./src/ConvexHull.cpp
		./src/Point.cpp

		./main.cpp
    	)
