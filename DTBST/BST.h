// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file includes all of the pieces of the BST implementation

/*
File: BST.h -- binary search tree implementation
Author: Hayley Yukihiro
CSIS215 - D01
Reference:  A Practical Introduction to Data Structures and Algorithm Analysis by Shaffer, DTBST Complete Implementation from Algorithms Tutorial Horizon, Programming Assignment 2 PowerPoint
*/

// Include the node implementation
#include "BSTNode.h"

// Include the dictionary ADT
#include "dictionary.h"
#include <string>


#ifndef BST_H
#define BST_H

using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E> {
private:
  BSTNode<Key,E>* root;   // Root of the BST
  
  int nodecount;         // Number of nodes in the BST

  // Private "helper" functions
  void clearhelp(BSTNode<Key, E>*);
  BSTNode<Key,E>* inserthelp(BSTNode<Key, E>*,
                              const Key&, const E&);
  BSTNode<Key,E>* deletemin(BSTNode<Key, E>*);
  BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
  BSTNode<Key,E>* removehelp(BSTNode<Key, E>*, const Key&);
  E* findhelp(BSTNode<Key, E>*, const Key&) const;
  void printhelp(BSTNode<Key, E>*, int) const;
  void vist(BSTNode<Key, E>*) const;

public:
  BST() { root = NULL; nodecount = 0; }  // Constructor
  
  //Note from Prof Sipantzi -- I've commented out the destructor
  //since you would have to change clearhelp() to make it work with
  //doubly-threaded trees and that is not part of the assignment.
  //~BST() { clearhelp(root); }            // Destructor

  void clear()   // Reinitialize tree
    { clearhelp(root); root = NULL; nodecount = 0; }

  // Insert a record into the tree.
  // k Key value of the record.
  // e The record to insert.
  void insert(const Key& k, const E& e) {
    root = inserthelp(root, k, e);
    nodecount++;
  }

  // Remove a record from the tree.
  // k Key value of record to remove.
  // Return: The record removed, or NULL if there is none.
  E* remove(const Key& k) {
    E* temp = findhelp(root, k);   // First find it
    if (temp != NULL) {
      root = removehelp(root, k);
      nodecount--;
    }
    return temp;
  }
  // Remove and return the root node from the dictionary.
  // Return: The record removed, null if tree is empty.
  E* removeAny() {  // Delete min value
    if (root != NULL) {
      E* temp = new E;
      *temp = root->element();
      root = removehelp(root, root->key());
      nodecount--;
      return temp;
    }
    else return NULL;
  }

  // Return Record with key value k, NULL if none exist.
  // k: The key value to find. */
  // Return some record matching "k".
  // Return true if such exists, false otherwise. If
  // multiple records match "k", return an arbitrary one.
  E* find(const Key& k) const { return findhelp(root, k); }

  // Return the number of records in the dictionary.
  int size() { return nodecount; }

  void print() const { // Print the contents of the BST
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
  }

  //In order printing of the tree
  void printInorder()
  {
	  BSTNode<Key, E>* current;						//Declare a current node
	  current = root;								//Current node is assigned to the root
	  //Loops down the  left side
	  while (current->left() != NULL) 				//Loops while the current node on the left side of the tree does not equal null
		  current = current->left();				//Current node goes to the left
	  //Loops down the right side
	  while (current->right() != NULL) {			//Loops while the current node on the right side of the tree does not equal null
		  vist(current);							//Prints out the current right node
		  if (current->getRightBit()) {				//If the current node has a right thread
			  current = current->right();			//Current node goes to the right
		  }
		  else {									
			  current = current->right();			//Current node goes to the right
			  while (!current->getLeftBit()) {		//While the current node does not have a left thread and only a regular pointer
				  current = current->left();		//Current node goes to the left
			  }
		  }
	  }
	  vist(current);								//Prints out the last node to the right
  }

  //Reverse printing of the tree
  void printReverse()
  {
	  BSTNode<Key, E>* current;						//Declare a current node
	  current = root;								//Current node is assigned to the root
	  //Loops down the right side
	  while (current->right() != NULL)				//Loops while the current node on the right side of the tree does not equal NULL
		  current = current->right();				//Current node goes to the right
	  //Loops down the left side
	  while (current->left() != NULL) {				//Loops while the current node on the left side of the tree does not equal NULL
		  vist(current);							//Prints out the current left node
		  if (current->getLeftBit()) {				//If the current node has a left thread
			  current = current->left();			//Current node goes to the left
		  }
		  else {									
			  current = current->left();			//Goes to the left
			  while (!current->getRightBit()) {		//If the current node has a left regular pointer
				  current = current->right();		//Current node goes to the right
			  }
		  }
	  }
	  vist(current);								//Prints out the last node to the left
  }
  
};

// Visit -- prints out root
template <typename Key, typename E>
void BST<Key, E>::vist(BSTNode<Key,E>* r) const {
    cout << "Node - " << r->element() << endl;
}

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
  if (root == NULL) return;
  clearhelp(root->left());
  clearhelp(root->right());
  delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it)
{
	//If the root is null
	if (root == NULL) {                                                                                      
		return new BSTNode<Key, E>(k, it, NULL, NULL);									     //Create a new tree node if it is null
	}
	//If the key record will be in the left side of the tree
	if (k < root->key()) {
		//If left is a thread
		if (root->getLeftBit()) {
			BSTNode<Key, E>* newNode;                                                       //Declare new node
			newNode = new BSTNode<Key, E>(k, it, NULL, NULL);                               //Creates new node 
			newNode->setRight(root, "thread");                                              //Right node is set to the root
			newNode->setLeft(root->left(), "thread");                                       //Left node is set to the left node of the root before newNode change
			root->setLeft(newNode, "regular");                                              //New node is set to the left of the root 
		}
		//If left is not a thread
		else
		{
			root->setLeft(inserthelp(root->left(), k, it), "regular");                     //Goes one more down the branch
		}

	}
	//If the key record will be in the right side of the tree
	else {
		//If right is a thread
		if (root->getRightBit()) {
			BSTNode<Key, E>* newNode;														//Declare new node
			newNode = new BSTNode<Key, E>(k, it, NULL, NULL);								//Create new node
			newNode->setLeft(root, "thread");												//Left node is set to the root
			newNode->setRight(root->right(), "thread");										//Right node is set to the right node of the root before newNode change
			root->setRight(newNode, "regular");												//New node is set to the right of the root
		}
		//If right is not a thread
		else {
			root->setRight(inserthelp(root->right(), k, it), "regular");					//Goes one more down the branch
		}
	}
	return root;																			//Return tree with node inserted
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
  if (rt->left() == NULL)
    return rt;
  else return getmin(rt->left());
}
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
  if (rt->left() == NULL) // Found min
    return rt->right();
  else {                      // Continue left
    rt->setLeft(deletemin(rt->left()),"");
    return rt;
  }
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
  if (rt == NULL) return NULL;    // k is not in tree
  else if (k < rt->key())
    rt->setLeft(removehelp(rt->left(), k),"");
  else if (k > rt->key())
    rt->setRight(removehelp(rt->right(), k),"");
  else {                            // Found: remove it
    BSTNode<Key, E>* temp = rt;
    if (rt->left() == NULL) {     // Only a right child
      rt = rt->right();         //  so point to right
      delete temp;
    }
    else if (rt->right() == NULL) { // Only a left child
      rt = rt->left();          //  so point to left
      delete temp;
    }
    else {                    // Both children are non-empty
      BSTNode<Key, E>* temp = getmin(rt->right());
      rt->setElement(temp->element());
      rt->setKey(temp->key());
      rt->setRight(deletemin(rt->right()),"");
      delete temp;
    }
  }
  return rt;
}

// Find a node with the given key value
template <typename Key, typename E>
E* BST<Key, E>::findhelp(BSTNode<Key, E>* root,
                              const Key& k) const {
  if (root == NULL) return NULL;          // Empty tree
  if (k < root->key())
    return findhelp(root->left(), k);   // Check left
  else if (k > root->key())
    return findhelp(root->right(), k);  // Check right
  else {
      E* temp = new E;
      *temp = root->element();
      return temp;  // Found it
  }
}

// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* root, int level) const {
  if (root == NULL) return;						// Empty tree
  if (!root->getLeftBit()) {					// Checks if the left is not a thread
	  printhelp(root->left(), level + 1);		// Do left subtree
  }
  for (int i=0; i<level; i++)					// Indent to level
    cout << "  ";
  cout << root->key() << "\n";					// Print node value
  if (!root->getRightBit()) {					//Checks if the right is not a thread
	  printhelp(root->right(), level + 1);		// Do right subtree
  }
}



#endif