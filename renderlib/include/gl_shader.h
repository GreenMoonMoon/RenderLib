//
// Created by jboisvert on 2021-07-15.
//

#ifndef RENDERLIB_GL_SHADER_H
#define RENDERLIB_GL_SHADER_H

#include <iostream>
#include <fstream>
#include <string>

#include "glad/glad.h"

namespace renderlib {
class Shader {
public:
    GLuint mProgram;
public:
    Shader();

    Shader(const char *vertex_source, const char *fragment_source);

    static Shader Default();

    void LoadFromFile(const char *vertexFile, const char *fragmentFile);

    void Use() const;

    GLuint GetProgram() const;

private:
    void Build(const char *vertex_source, const char *fragment_source);

    static bool ValidateShader(GLuint shader, const char *type);
};

}
#endif //RENDERLIB_GL_SHADER_H
