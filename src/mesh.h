//
// Created by jboisvert on 2021-07-15.
//
#include "app.h"

#ifndef RENDERLIB_MESH_H
#define RENDERLIB_MESH_H

class Shader;

class Mesh {
private:
    float *mVertices;
    int *mIndices;
    int mVertexCount;
    int mIndiceCount;
    GLuint mVBO;
    GLuint mVAO;
    GLuint mEBO;

public:
    Mesh() {}

    Mesh(float *vertices, int vertexCount);

    Mesh(float *vertices, int vertexCount, int *indices, int indiceCount);

    void Draw(Shader &shader) const;

    void DrawArray(Shader &shader) const;
};

struct Cube : public Mesh {
    Cube(float width, float height, float depth);
};


#endif //RENDERLIB_MESH_H
