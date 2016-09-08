cmake_minimum_required(VERSION 2.8.9)
project(Grain CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set (CMAKE_BUILD_TYPE Release)
set (CMAKE_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set (LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_DIR})

add_compile_options(-std=c++11 -g -Wall)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

set(PROJECT_SRCS 
	${PROJECT_SOURCE_DIR}/include/Vector.h
	${PROJECT_SOURCE_DIR}/include/IncompatibleSizeException.h
	)

if(NOT MSVC)
	#list(APPEND CMAKE_CXX_FLAGS -std=c++11 ${CMAKE_CXX_FLAGS} -g -Wall)
endif()

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
add_library(${PROJECT_NAME}_static STATIC ${PROJECT_SRCS})
set_target_properties(${PROJECT_NAME}_static PROPERTIES LINKER_LANGUAGE CXX)

add_executable(mainTest ${PROJECT_SOURCE_DIR}/test/main.cpp)


