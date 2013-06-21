file(GLOB sources "*.cpp")

add_subdirectory( Engine )

include_directories( ${CMAKE_SOURCE_DIR}/src/Engine )
link_directories( ${CMAKE_BINARY_DIR}/src/Engine )

add_executable("render" ${sources})

target_link_libraries("render" engine)
if(Cotire)
    cotire(stranded)
endif(Cotire)
