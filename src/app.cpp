//
// Created by MoonMoon on 2021-08-04.
//
#include <iostream>
#include "app.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void glfw_error_callback(int code, const char* description) {
    std::cerr << description << '\n';
}

namespace renderlib {
    Window::Window() {
        std::cout << "[RENDERLIB]" << "Initialize GLFW\n";
        glfwInit();
        glfwSetErrorCallback(glfw_error_callback);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 600, "Main", nullptr, nullptr);
        if (window == nullptr) {
            std::cerr << "GLFW: Could not create a window.";
            glfwTerminate();
            return;
        }

        std::cout << "[RENDERLIB]" << "Set context to window\n";
        glfwMakeContextCurrent(window);

        //Load glad
        std::cout << "[RENDERLIB]" << "Loading Glad\n";
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "GLAD: Failed to initialize GLAD";
            return;
        }

        //Create the OpenGL viewport
        std::cout << "[RENDERLIB]" << "Creating viewport\n";
        glViewport(0, 0, 800, 600);
        glfwSetWindowSizeCallback(window, framebuffer_size_callback);
    }

    void Window::Update() const {
        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.2f, 0.2f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::ProcessInput() const {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(window);
    }

    void Window::Close() {
        glfwTerminate();
    }
}