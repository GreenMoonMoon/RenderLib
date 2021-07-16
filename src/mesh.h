//
// Created by jboisvert on 2021-07-15.
//
#include "core.h"
#include "shader.h"

#ifndef RENDERLIB_MESH_H
#define RENDERLIB_MESH_H


class Mesh {
private:
    float *mVertices;
    int mVertexCount;
    GLuint mVBO;
    GLuint mVAO;

public:
    Mesh();

    void Draw(Shader &shader) const;
};


#endif //RENDERLIB_MESH_H
