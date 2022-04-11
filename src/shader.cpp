//
// Created by jboisvert on 2021-07-15.
//
#include "shader.h"

const char *basic_vs_source = "#version 460 core\n"
                              "layout (location = 0) in vec3 aPos;\n"
                              "\n"
                              "void main()\n"
                              "{\n"
                              "\tgl_Position = vec4(aPos, 1.0);\n"
                              "}";
const char *basic_fs_source = "#version 460 core\n"
                              "out vec4 FragColor;\n"
                              "\n"
                              "void main()\n"
                              "{\n"
                              "\tFragColor = vec4(1.0f);\n"
                              "}";

Shader::Shader() {
    mProgram = -1;
}

Shader::Shader(const char *vertex_source, const char *fragment_source) {
    Build(vertex_source, fragment_source);
}

void Shader::LoadFromFile(const char *vertexFile, const char *fragmentFile) {
    std::ifstream inVertexStream{vertexFile};
    if (inVertexStream.fail()) {
        std::cerr << "Could not open vertex shader file : " << vertexFile << '\n';
        return;
    }
    std::string vertexSource((std::istreambuf_iterator<char>(inVertexStream)), std::istreambuf_iterator<char>());
    inVertexStream.close();

    std::ifstream inFragmentStream{fragmentFile};
    if (inVertexStream.fail()) {
        std::cerr << "Could not open fragment shader file : " << vertexFile << '\n';
        return;
    }
    std::string fragmentSource((std::istreambuf_iterator<char>(inFragmentStream)), std::istreambuf_iterator<char>());
    inVertexStream.close();

    Build(vertexSource.c_str(), fragmentSource.c_str());
}

void Shader::Build(const char *vertex_source, const char *fragment_source) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_source, nullptr);
    glCompileShader(vertexShader);
    if (!ValidateShader(vertexShader, "vertex")) {
        return;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glCompileShader(fragmentShader);
    glShaderSource(fragmentShader, 1, &fragment_source, nullptr);
    glCompileShader(fragmentShader);
    if (!ValidateShader(fragmentShader, "fragment")) {
        return;
    }

    mProgram = glCreateProgram();
    glAttachShader(mProgram, vertexShader);
    glAttachShader(mProgram, fragmentShader);
    glLinkProgram(mProgram);

    int link_success;
    glGetProgramiv(mProgram, GL_LINK_STATUS, &link_success);
    if (!link_success) {
        char link_info_log[512];
        glGetProgramInfoLog(mProgram, 512, nullptr, link_info_log);
        std::cerr << "GL: Program linking failed!\n\t" << link_info_log << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

bool Shader::ValidateShader(GLuint shader, const char *type) {
    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, info_log);
        std::cerr << "GL:" << type << " Shader compilation failed!\n\t" << info_log << std::endl;
    }
    return bool(success);
}

void Shader::Use() const {
    glUseProgram(mProgram);
}