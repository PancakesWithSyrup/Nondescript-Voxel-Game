#pragma once
#include "Block.h"
#include "Camera.h"

class Chunk {
public:
	Chunk();
	~Chunk();
	void render(Camera &camera);

	static const int CHUNK_SIZE = 16;
private:
	Block ***blocks;
};
