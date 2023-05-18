#include "Block.h"

Block::Block() : mesh(vertices, indices) {

}

Block::~Block() {

}

void Block::draw(glm::vec3 position, Camera& camera) {
    this->mesh.draw(position, camera);
}

void Block::setActive(bool newActive) {
    this->active = active;
}

bool Block::isActive() {
    return active;
}

