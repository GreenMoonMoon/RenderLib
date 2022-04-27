set(RENDERLIB_SOURCES
        src/renderlib.cpp
        src/gl_shader.cpp)

set(RENDERLIB_HEADERS
        include/gl.h
        include/gl_shader.h
        include/renderlib.h)

set(RENDERLIB_DEPENDENCIES
        ${glm_INCLUDE_DIR}
        ${glfw_INCLUDE_DIR}
        ${glad_INCLUDE_DIR})

add_library(renderlib STATIC ${RENDERLIB_SOURCES} ${RENDERLIB_HEADERS})
target_link_libraries(renderlib glfw glad)
target_include_directories(renderlib PUBLIC ${RENDERLIB_DEPENDENCIES} include)