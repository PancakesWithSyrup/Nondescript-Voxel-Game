#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Camera.h"
#include "BlockMesh.h"

enum class BlockType {
	AIR = 0,
	GRASS,
	DIRT,
	STONE
};

class Block {
public:
	Block();
	~Block();

	void draw(glm::vec3 position, Camera& camera);

	bool isActive();
	void setActive(bool newActive);
private:
	bool active;
	BlockType blockType;
};

