/*
* File:   LRUBufferBlock.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/

#pragma once
#include "BufferPoolADT.h"
#include "BufferBlock.h"
#include "constants.h"
#include <iostream>
#include <fstream>

class LRUBufferPool : public BufferPoolADT {
private:
	fstream input;
	BufferBlock LRUpool[POOL_SIZE];																//Buffer pool variable that consists of a variable that takes X amount of bufferblocks. Utilized the global variable for pool size in constants.h
	int used;																					//Holds the int used recently in getBytes

public:
	//Constructors
	LRUBufferPool() {}																			//Default constructor
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {
		char* data = new char[blockSize + 1];													//Created temp data pointer for file read in
		input.open(filename.c_str(), fstream::in | fstream::binary);							//Gets filename for the buffer and opens it
		for (int i = 0; i < poolSize;) {														//Loop through the file and read in text data in order
			input.read(data, blockSize);														//Reads in data for the blockSize
			BufferBlock temp(data, blockSize);													//Create temp object to hold buffer block information
			LRUpool[i].setBlock(temp.getBlock());												//Sets the block information by getting the block information being held by the temp variable
			LRUpool[i].setID(i);																//Sets block ID from order of read in
			i++;
			input.seekg(blockSize * i);															//Sets the position of the next data set to be extracted from the file 
		}
	}

	//Destructor
	~LRUBufferPool() {};																		//Default destructor

	//getBytes:  Copy "sz" bytes from position "pos" of the buffered storage to "space"
	void getBytes(char* space, int sz, int pos) {
		bool found = false;																		//Bool variable to determine if the data is found
		bool move = false;																		//Bool variable to determine if data moved
		int id = pos / BLOCKSIZE;																//Variable to hold the id number which is the position of the blocksize
		int start = pos % BLOCKSIZE;															//Variable to hold the next data selection
		BufferBlock block;																		//Declare block object

		//Find data and set buffer
		for (int i = 0; i < POOL_SIZE && found == false; i++) {									//Loops through pool and finds data
			if (LRUpool[i].getID() == id) {														//If a pool ID matches the specific id a position in the block
				LRUpool[i].getData(start, sz, space);											//Get the datat at that int i 									
				block.setBlock(LRUpool[i].getBlock());											//Set the block at int i of the pool
				block.setID(id);																//Set the ID at int i 
				used = i;																		//Most recently used variable assigned to the int i used 
				found = true;																	//Assign true to found variable
			}
		}
		//If data is not found, find the data in from the file and read into buffer
		if (!found) {																			//If data is not found
			char* data = new char[BLOCKSIZE + 1];												//Gets filename for the buffer and opens it
			input.seekg(BLOCKSIZE*id);															//Sets the position of the next block data
			input.read(data, BLOCKSIZE);														//Reads in the block data
			BufferBlock temp(data, BLOCKSIZE);													//Create temp object to hold buffer block information
			block.setBlock(temp.getBlock());													//Set block with the temp block data from the read in
			block.setID(id);																	//Set id of the block
			block.getData(start, sz, space);													//Get the data of the block
		}
		//LRU read from disk
		if (block.getID() == LRUpool[0].getID()) {												//Front situation
			move = true;
		}
		else if (found) {
			for (int k = used; k > 0; k--) {													//Middle and end situations
				LRUpool[k].setBlock(LRUpool[k - 1].getBlock());
				LRUpool[k].setID(LRUpool[k - 1].getID());
			}
			LRUpool[0].setBlock(block.getBlock());
			LRUpool[0].setID(block.getID());
			move = true;
		}
		if (move == false) {
			for (int j = POOL_SIZE-1; j > 0; j--) {												//New number situation
				LRUpool[j].setBlock(LRUpool[j - 1].getBlock());
				LRUpool[j].setID(LRUpool[j - 1].getID());
			}
			LRUpool[0].setBlock(block.getBlock());
			LRUpool[0].setID(block.getID());
		}
	}

	//printBufferBlockOrder: Print the order of the buffer blocks using the block id numbers
	void printBufferBlockOrder() {
		cout << "The buffer block order from most recently used to LRU:  " << endl << "    ";;
		for (int i = 0; i < POOL_SIZE; i++) {
			cout << LRUpool[i].getID() << " ";
		}
		cout << endl;
	}
	
	//getLRUBlockID: Get the block id number of the least recently used buffer block
	int getLRUBlockID() {
		return LRUpool[POOL_SIZE].getID();
	}




};
