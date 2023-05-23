#pragma once

#include <vector>

#include <glad/glad.h>

#include "Quad.h"
#include "../Shader.h"
#include "../Camera.h"

class QuadMesh {
public:
	QuadMesh(enum class QUAD_DIRECTION pDirection);
	~QuadMesh();
	void draw(glm::vec3 position, Camera& camera);

private:
	Shader shader;
	GLuint vao, vbo, ebo;

	std::vector<GLint> vertices;

	std::vector<GLint> upVertices = {
		-1, 0, 1,
		1, 0, 1,
		1, 0, -1,
		-1, 0, -1
	};

	std::vector<GLint> leftVertices = {
		0, 1, 1,
		0, -1, 1,
		0, -1, -1,
		0, 1, -1
	};

	std::vector<GLint> frontVertices = {
		-1, -1, 0,
		1, -1, 0,
		1, 1, 0,
		-1, 1, 0
	};

	std::vector<GLint> indices = {
		0, 1, 2,
		0, 2, 3
	};
};

