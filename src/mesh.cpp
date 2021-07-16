//
// Created by jboisvert on 2021-07-15.
//

#include "mesh.h"

Mesh::Mesh() {
    float _vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };
    mVertices = _vertices;
    mVertexCount = 3;

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::Draw(Shader &shader) const {
    glUseProgram(shader.mProgram);
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, mVertexCount);
}
