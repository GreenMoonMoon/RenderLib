//
// Created by jboisvert on 2021-07-15.
//
#include "mesh.h"
#include "gl_shader.h"

void Mesh::Build(float *vertices, int vertexCount, int *indices, int indiceCount) {
    mVertexCount = vertexCount;
    mIndiceCount = indiceCount;

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertexCount * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndiceCount * sizeof(int), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(float *vertices, int vertexCount) : mVertices(vertices), mVertexCount(vertexCount) {
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertexCount * sizeof(float), mVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::DrawArray(Shader &shader) const {
    glUseProgram(shader.mProgram);
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Mesh::Draw(Shader &shader) const {
    glUseProgram(shader.mProgram);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    delete (mVertices);
    delete (mIndices);
}

// Generators
Mesh& GenerateCubeMesh(float sizeX, float sizeY, float sizeZ) {
    float *vertices{new float[]{
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f
    }};
    int *indices{new int[]{
            0, 4, 5, 5, 1, 0,
            1, 5, 6, 6, 2, 1,
            2, 6, 7, 7, 2, 3,
            3, 7, 4, 4, 3, 0,
            0, 1, 3, 3, 1, 2,
            4, 5, 7, 7, 5, 6
    }};

    Mesh mesh = new Mesh();
    mesh.Build(vertices, 8, indices, 36);
    return mesh;
}
