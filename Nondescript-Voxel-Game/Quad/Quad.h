#pragma once

#include <vector>

#include <glad/glad.h>

#include "QuadMesh.h"
#include "../Camera.h"

enum class QUAD_DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	FRONT,
	BACK
};

class Quad {
public:
	Quad(QUAD_DIRECTION direction);
	~Quad();

	QUAD_DIRECTION getQuadDirection() const;
	void draw(glm::vec3 position, Camera& camera);
private:
	QUAD_DIRECTION direction;

};

