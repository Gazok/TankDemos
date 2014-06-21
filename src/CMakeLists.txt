file(GLOB sources *.cpp *.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)

add_executable(camera ${sources})

target_link_libraries(camera tank)
