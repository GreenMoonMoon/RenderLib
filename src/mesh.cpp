//
// Created by jboisvert on 2021-07-15.
//

#include "mesh.h"

Mesh::Mesh() {
    float _vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
    vertices = _vertices;
    vertexCount = 3;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9, vertices, GL_STATIC_DRAW);
}

void Mesh::Draw() {}
