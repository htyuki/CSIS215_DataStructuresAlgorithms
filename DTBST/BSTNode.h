// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include for access to the complete binary node
// template implementation

/*
File: BSTNode.h -- binary tree node implementation
Author: Hayley Yukihiro
CSIS215 - D01
Reference:  A Practical Introduction to Data Structures and Algorithm Analysis by Shaffer, DTBST Complete Implementation from Algorithms Tutorial Horizon
*/

#include "book.h"
#include "BinNode.h"


#ifndef BSTNODE_H
#define BSTNODE_H

// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E> {
private:
  Key k;                  // The node's key
  E it;                   // The node's value
  BSTNode* lc;            // Pointer to left child
  BSTNode* rc;            // Pointer to right child
  bool leftTh : 1;		 //Boolean instance variable to indicate whether a left node pointer is a thread 
  bool rightTh : 1;      //Boolean instance variable to indicate wtheter a right node pointer is a thread


public:
  // Two constructors -- with and without initial values
  BSTNode() { lc = rc = NULL; }
  BSTNode(Key K, E e, BSTNode* l =NULL, BSTNode* r =NULL)
  {
	  k = K; it = e; lc = l; rc = r; leftTh = true; rightTh = true;
  }
  ~BSTNode() {}             // Destructor

  // Functions to set and return the value and key
  E& element() { return it; }
  void setElement(const E& e) { it = e; }
  Key& key() { return k; }
  void setKey(const Key& K) { k = K; }

  // Functions to set and return the children
  inline BSTNode* left() const { return lc; }
  void setLeft(BinNode<E>* b, string s) {
	 lc = (BSTNode*)b; 
	 //Checks if the string reads "thread"
	 if (s == "thread")                          
		 leftTh = true;
	 else
		 leftTh = false;                              
  }
  inline BSTNode* right() const { return rc; }
  void setRight(BinNode<E>* b, string s) {
	 rc = (BSTNode*)b;
	 //Checks if the string reads "thread"
	 if (s == "thread")
		 rightTh = true;
	 else
		 rightTh = false;
  }

  //Functions to set and get access the right and left boolean instance variables
  inline int getLeftBit() const {
	  return leftTh;                            //Gets the left thread 
  }
  void setLeftBit(bool left)
  {
	  leftTh = left;							//Sets the left thread
  }
  inline int getRightBit() const {
	  return rightTh;							//Gets the right thread
  }
  void setRightBit(bool right)
  {
	  rightTh = right;							//Sets the right thread
  }

  // Return true if it is a leaf, false otherwise
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};

#endif