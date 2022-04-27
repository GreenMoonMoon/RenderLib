cmake_minimum_required(VERSION 3.19)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

project(RenderLib)


# DEPENDENCIES
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)
set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
)
FetchContent_Populate(glm)

FetchContent_MakeAvailable(glad glfw)

# TEST PROJECT
add_subdirectory(renderlib_tests)


# CURRENT TEST EXECUTABLE
set(LIB_FILES
        "src/lib.cpp"
#        "src/mesh.cpp"
        "src/shader.cpp"
        "src/shader.h"
#        "src/app.cpp"
        )

add_library(renderlib STATIC)
target_sources(renderlib PRIVATE ${LIB_FILES})
target_link_libraries(renderlib glfw glad)
target_include_directories(renderlib PUBLIC ${glm_SOURCE_DIR})

add_executable(test_renderlib app/main.cpp)
#set_target_properties(test_renderlib
#        PROPERTIES
#        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES}/lib"
#        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES}/lib"
#        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES}/bin"
#        )
target_link_libraries(test_renderlib renderlib)
target_include_directories(test_renderlib PUBLIC src)

add_custom_command(
        TARGET test_renderlib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:test_renderlib>/resources)