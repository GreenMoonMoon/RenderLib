#include "renderlib.h"

using namespace renderlib;

const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
};

const float colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

int main() {
    auto window = initialize("Example App", 800, 600);
    set_clear_color(0.2f, 0.2f, 0.2f, 1.0f);

    // Create a vertex buffer object
    GLuint vertex_positions_vbo;
    glGenBuffers(1, &vertex_positions_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_positions_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);

    GLuint vertex_colors_vbo;
    glGenBuffers(1, &vertex_colors_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_colors_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colors, GL_STATIC_DRAW);

    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays(1, &vao);

    // Bind the vertex buffer objects to the vertex array object directly
    glBindVertexArray(vao);
    glEnableVertexArrayAttrib(vao, 0); // position
    glEnableVertexArrayAttrib(vao, 1); // color

    // Specify the vertex attributes data format and bind it to the shader locations
    // Note: the indexes within the vertex buffer binding point need not match the shader attribute locations
    glBindVertexBuffer(0, vertex_positions_vbo, 0, 3 * sizeof(float));
    glBindVertexBuffer(1, vertex_colors_vbo, 0, 3 * sizeof(float));
    glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);
    glVertexArrayAttribFormat(vao, 1, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(1, 1);

    auto shader = Shader::Default();
    float angle = 0.0f;

    //TODO: encapsulate this in a class
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glBindVertexArray(vao);
        shader.Use();

        // Test rotations matrix
        auto rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle += 0.1f), glm::vec3(0.0f, 0.0f, 1.0f));
        auto rotation_matrix_uniform = glGetUniformLocation(shader.GetProgram(), "rotation");
        if (rotation_matrix_uniform >= 0) {
            glUniformMatrix4fv(rotation_matrix_uniform, 1, GL_FALSE, glm::value_ptr(rotation_matrix));
        } else {
            std::cout << "Could not find uniform 'rotation' in shader" << std::endl;
        }

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
