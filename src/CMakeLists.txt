file(GLOB sources "*.cpp")

add_subdirectory(Engine)

include_directories( ${CMAKE_SOURCE_DIR}/src/Engine )
link_directories( ${CMAKE_BINARY_DIR}/src/Engine )

add_executable(render ${sources})

target_link_libraries(render tank ${OPENGL_LIBRARIES} ${SFML_LIBRARIES}
    ${GLEW_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
