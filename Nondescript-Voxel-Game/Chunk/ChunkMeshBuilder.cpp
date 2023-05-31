#include "ChunkMeshBuilder.h"
#include "Chunk.h"

// TODO: Make this by reference, not value.
ChunkMeshBuilder::ChunkMeshBuilder(Block blocks[][16][16]) {
	for (int x = 0; x < CHUNK_SIZE; x++)
	for (int y = 0; y < CHUNK_SIZE; y++)
	for (int z = 0; z < CHUNK_SIZE; z++) {

	}
}

ChunkMeshBuilder::~ChunkMeshBuilder() {

}

void ChunkMeshBuilder::buildMesh() {

}

