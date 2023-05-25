#pragma once
#include <vector>

#include <glad/glad.h>

#include "../Shader.h"
#include "../Camera.h"

class BlockMesh {
public:
	BlockMesh();
	~BlockMesh();

	void draw(glm::vec3 position, Camera &camera);
private:
	Shader shader;
	GLuint vao, vbo, ebo;
};

