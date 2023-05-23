#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "BlockMesh.h"
#include "../Game.h"

BlockMesh::BlockMesh(std::vector<GLint> p_vertices, std::vector<GLint> p_indices) : shader("shaders/shader.vert", "shaders/shader.frag") {
    this->vertices = p_vertices;
    this->indices = p_indices;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLint), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), &indices[0], GL_STATIC_DRAW);

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
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

