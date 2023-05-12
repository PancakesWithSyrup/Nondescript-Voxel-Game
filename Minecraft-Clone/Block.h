#pragma once

enum BlockType {
	DEFAULT,
	GRASS,
	DIRT
};

class Block {
public:
	Block();
	~Block();

	bool isActive();
	void setActive(bool newActive);
private:
	BlockType blockType;
	bool active;

};

