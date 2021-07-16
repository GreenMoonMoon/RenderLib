#include <iostream>
//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
#include "src/core.h"

#include "src/mesh.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
    //initialize a window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Main", NULL, NULL);
    if (window == nullptr) {
        std::cerr << "GLFW: Could not create a window.";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Load glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "GLAD: Failed to initialize GLAD";
        return -1;
    }

    //Create the OpenGL viewport
    glViewport(0, 0, 800, 600);
    glfwSetWindowSizeCallback(window, framebuffer_size_callback);

    //Set debug object
    Mesh mesh = Mesh();

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.2f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mesh.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}