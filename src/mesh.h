//
// Created by jboisvert on 2021-07-15.
//
#include "core.h"

#ifndef RENDERLIB_MESH_H
#define RENDERLIB_MESH_H


class Mesh {
private:
    float* vertices;
    int vertexCount;
    GLuint vbo;

public:
    Mesh();

    void Draw();
};


#endif //RENDERLIB_MESH_H
