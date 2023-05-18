#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"
#include "Mesh.h"

enum BlockType {
	DEFAULT,
	GRASS,
	DIRT
};

class Block {
public:
	Block();
	~Block();

	void draw(glm::vec3 position, Camera& camera);

	bool isActive();
	void setActive(bool newActive);
private:
	std::vector<GLint> vertices = {
		-1, -1, -1, 
		1, -1, -1, 
		1, 1, -1,
		-1, 1, -1,
		-1, -1, 1,
		1, -1, 1,
		1, 1, 1,
		-1, 1, 1
	};

	std::vector<GLint> indices = {
		0, 1, 3, 3, 1, 2, // back
		1, 5, 2, 2, 5, 6, // right
		5, 4, 6, 6, 4, 7, // front
		4, 0, 7, 7, 0, 3, // left
		3, 2, 7, 7, 2, 6, // top
		4, 5, 0, 0, 5, 1 // bottom
	};

	bool active;
	BlockType blockType;
	Mesh mesh;
};

