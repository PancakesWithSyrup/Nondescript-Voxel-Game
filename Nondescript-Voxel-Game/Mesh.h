#pragma once
#include <vector>

#include <glad/glad.h>

#include "Shader.h"
#include "Camera.h"

class Mesh {
public:
	Mesh(std::vector<float> p_Vertices);
	~Mesh();

	void draw(glm::vec3 position, Camera &camera);
private:
	std::vector<float> vertices;
	Shader shader;
	GLuint vao, vbo;
	std::vector<GLuint> buffer;
};

