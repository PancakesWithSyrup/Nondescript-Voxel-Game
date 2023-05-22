#pragma once
#include <vector>

#include <glad/glad.h>

#include "../Shader.h"
#include "../Camera.h"

class BlockMesh {
public:
	BlockMesh(std::vector<GLint> p_vertices, std::vector<GLint> p_indices);

	~BlockMesh();

	void draw(glm::vec3 position, Camera &camera);
private:
	std::vector<GLint> vertices, indices;

	Shader shader;
	GLuint vao, vbo, ebo;
};

