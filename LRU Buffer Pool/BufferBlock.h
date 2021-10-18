/*
* File:   BufferBlock.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/

#pragma once
#include <iostream>
#include "BufferBlockADT.h"

class BufferBlock : public BufferblockADT {
private:
	//Instance variables:
		int blockID;
		char* block;
		int size;
public:
	//Constructor
	BufferBlock() {}
	BufferBlock(char *data, int sz = 4096) {           //initilaze blocks
		size = sz;
		block = new char[size];
		for (int i = 0; i <= size - 1 ; i++) {
			block[i] = data[i];
		}
	}
	//Destructor
	virtual ~BufferBlock() {}

	//getData: read the block from pos to pos + sz-1 (or to the end of the block)
	void getData(int pos, int sz, char* data) {
		int blck = 0;															//Variable to hold data for each block
		for (int i = pos; i <= (pos + (sz - 1)); i++) {							//Loops out the data and puts the data in data[blck]
			data[blck] = block[i];
			blck++;
		}
	}

	//setID: sets the block ID
	void setID(int id) {
		this->blockID = id;
	}

	//getID: returns the block ID
	int getID() const {
		return this->blockID;
	}

	//getBlocksize: returns the size of the block
	int getBlocksize() const {
		return this->size;
	}

	//getBlock: returns a block
	char* getBlock() const {
		return this->block;
	}

	//setBlock: sets a block
	void setBlock(char* blk) {
		this->block = blk;
	}
};
