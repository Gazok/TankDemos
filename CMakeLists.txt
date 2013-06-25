CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(RenderTest)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(SFML 2.0 REQUIRED system window graphics)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost 1.53.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif(NOT MSVC)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
endif (APPLE)

set(CMAKE_BUILD_TYPE Debug)

option(Debug "Debug mode" ON)
if(NOT MSVC)
    option(Warn "Compile using all warnings" ON)
endif(NOT MSVC)

if(Warn)
    set (CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
endif(Warn)

if(Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
endif(Debug)

set (CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)
file(COPY "res" DESTINATION ${CMAKE_BINARY_DIR})
