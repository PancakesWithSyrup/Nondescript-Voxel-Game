#include "Block.h"

Block::Block() {
    active = true;
    blockType = BlockType::GRASS;
}

Block::~Block() {

}

void Block::draw(glm::vec3 position, Camera& camera) {
    BlockMesh mesh;
    mesh.draw(position, camera);
}

void Block::setActive(bool newActive) {
    this->active = active;
}

bool Block::isActive() {
    return active;
}

