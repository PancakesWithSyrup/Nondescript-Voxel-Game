#pragma once

#include <vector>

#include "../Block/Block.h"

class ChunkMeshBuilder {
public:
	ChunkMeshBuilder(Block blocks[][16][16]);
	~ChunkMeshBuilder();
	void buildMesh();
private:
	std::vector<int> vertices;
	std::vector<int> indices;
};

