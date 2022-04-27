# Build examples
add_executable(example_app example_app/src/main.cpp)
target_link_libraries(example_app PUBLIC renderlib)

## Copy resources to the install directory
#add_custom_command(TARGET example_app POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        example_app/resources ${CMAKE_INSTALL_PREFIX}/resources)