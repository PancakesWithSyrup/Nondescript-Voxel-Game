#include "Block.h"

Block::Block() {

}

Block::~Block() {

}

bool Block::isActive() {
    return active;
}

void Block::setActive(bool newActive) {
    this->active = active;
}
