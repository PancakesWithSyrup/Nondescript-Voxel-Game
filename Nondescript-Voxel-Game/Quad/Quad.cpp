#include "Quad.h"

Quad::Quad(QUAD_DIRECTION direction) {
    this->direction = direction;
}

Quad::~Quad()
{
}


void Quad::draw(glm::vec3 position, Camera& camera) {
    QuadMesh mesh(direction);
    mesh.draw(position, camera);
}

QUAD_DIRECTION Quad::getQuadDirection() const {
    return direction;
}