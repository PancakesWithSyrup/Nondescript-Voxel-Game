#pragma once

#include "../Block/Block.h"
#include "ChunkMesh.h"

static const int CHUNK_SIZE = 16;

class Chunk {
public:
	Chunk(Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE]);
	~Chunk();

	void buildMesh();
private:
	Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
	ChunkMesh mesh;
};

