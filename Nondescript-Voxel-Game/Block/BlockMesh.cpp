#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "BlockMesh.h"
#include "../Game.h"

const std::vector<GLint> cubeVertices = {
        -1, -1, -1,
        1, -1, -1,
        1, 1, -1,
        -1, 1, -1,
        -1, -1, 1,
        1, -1, 1,
        1, 1, 1,
        -1, 1, 1
};

const std::vector<GLint> cubeIndices = {
    0, 1, 3, 3, 1, 2, // back
    1, 5, 2, 2, 5, 6, // right
    5, 4, 6, 6, 4, 7, // front
    4, 0, 7, 7, 0, 3, // left
    3, 2, 7, 7, 2, 6, // top
    4, 5, 0, 0, 5, 1 // bottom
};

BlockMesh::BlockMesh() : shader("shaders/shader.vert", "shaders/shader.frag") {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, cubeVertices.size() * sizeof(GLint), &cubeVertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, cubeIndices.size() * sizeof(GLint), &cubeIndices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 3 * sizeof(GLint), (void*)0);
    
    glBindVertexArray(0);
}

BlockMesh::~BlockMesh() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void BlockMesh::draw(glm::vec3 position, Camera &camera) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader.use();
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
    shader.setMat4("projection", projection);

    glm::mat4 view = camera.GetViewMatrix();
    shader.setMat4("view", view);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    float angle = 0.0f;
    model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
    shader.setMat4("model", model);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(cubeIndices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

