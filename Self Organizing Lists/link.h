#ifndef LINK_H
#define	LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
public:
  E element;         // Value for this node
  Link *next;        // Pointer to next node in list
  int numberAccess;   //Variable that holds the number of accessed times of a item
  int counter = 0;

  // Constructors
  Link(const E& elemval, int count = 0, Link* nextval = NULL)
  {element = elemval;  next = nextval; counter = count;}
  Link(Link* nextval =NULL) { next = nextval; }

  //Gets the number of times accessed of a list item
  int getAccess() {
	  return numberAccess;
  }

  //Sets the number of times accessed of a list item
  void setAccess(int t) {
	  numberAccess = t;
  }
};

#endif