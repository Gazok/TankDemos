file(GLOB sources *.cpp *.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)

add_executable(test ${sources})

target_link_libraries(test tank)
