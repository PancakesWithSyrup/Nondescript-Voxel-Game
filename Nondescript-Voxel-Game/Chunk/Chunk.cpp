#include "Chunk.h"
#include "ChunkMeshBuilder.h"

Chunk::Chunk(Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE]) {
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_SIZE; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				this->blocks[x][y][z] = blocks[x][y][z];
			}
		}
	}
}

Chunk::~Chunk() {

}

void Chunk::buildMesh() {
	ChunkMeshBuilder builder(blocks);
	builder.buildMesh();
}