//
// Created by jboisvert on 2022-04-11.
//
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#ifndef RENDERLIB_GL_H
#define RENDERLIB_GL_H

void glfw_error_callback(int code, const char* description) {
    std::cerr << description << '\n';
}

GLFWwindow *initialize() {
    if(!glfwInit()) {
        std::cerr << "Unable to initialize GLFW" << std::endl;
        exit(-1);
    }
    glfwSetErrorCallback(glfw_error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "RenderLib", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Unable to load OpenGL functions" << std::endl;
        exit(-1); //FIXME: Should it return a value instead?
    }

    return window;
}

void cleanup(GLFWwindow *window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void print_gl_infos(){
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *glsl_version = glGetString(GL_SHADING_LANGUAGE_VERSION);

    GLint major;
    GLint minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    std::cout << "OpenGL infos:\n"
        << "\tRenderer: " << renderer << std::endl
        << "\tVendor: " << vendor << std::endl
        << "\tVersion: " << version << std::endl
        << "\tGLSL version: " << glsl_version << std::endl
        << "\tOpenGL version: " << major << '.' << minor << std::endl
        << std::endl;
}

#endif //RENDERLIB_GL_H
