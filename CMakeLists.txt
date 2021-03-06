cmake_minimum_required(VERSION 3.19)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

project(RenderLib)


# DEPENDENCIES
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git)
set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git)
FetchContent_Populate(glm)

FetchContent_MakeAvailable(glad glfw)
add_subdirectory(renderlib)
add_subdirectory(examples)