//
// Created by jboisvert on 2021-07-15.
//

#ifndef RENDERLIB_SHADER_H
#define RENDERLIB_SHADER_H

#include <iostream>
#include <fstream>
#include <string>

#include "core.h"

class Shader {
public:
    GLuint mProgram;
public:
    Shader();

    Shader(const char *vertex_source, const char *fragment_source);

    void LoadFromFile(const char *vertexFile, const char *fragmentFile);

    void Use() const;

private:
    void Build(const char *vertex_source, const char *fragment_source);

    bool ValidateShader(GLuint shader, const char* type);
};

#endif //RENDERLIB_SHADER_H
