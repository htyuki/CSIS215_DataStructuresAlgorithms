/*
* File:   MoveToFront.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/
#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

template <typename E>
class MoveToFront : public SelfOrderedListADT<E> {
private:
	LList<E> l;
	int comp;
	int counter;

public:
	//Constructor
	MoveToFront() {
		comp = 0;										//initialize number of comparisons to zero
		counter = 0;
	}
	//Destructor
	~MoveToFront() {}

	//reorder: Reorders list items by moving items to the front when they are accessed
	void reorder() {
		counter = l.getCount();
		int moveItem = l.getTimes();					//Assign variable of an item to be moved
		l.next();										//Go to the next element in the list
		int nextItem = l.getTimes();					//Assign variable of next item to the number of accesess of the item
		l.prev();										//Go back to the item being moved
		E temp = l.remove();							//Remove item
		l.setTimes(nextItem);							//Update number of accesses
		l.moveToStart();								//Move to the start of the list
		int frontItem = l.getTimes();					//Get the number of access times from the item at the front of the list
		l.insert(temp, counter);									//Insert removed item
		l.setTimes(moveItem);							//Update number of accesses for the movved item
		l.next();										//Advance the list
		l.setTimes(frontItem);							//Update access times for the front item
	}

	//find: Look for given item in the list
	bool find(const E& it) {
		bool found = false;							//Boolean instance variable
		l.moveToStart();							//Moves position of current element to beginning of list
		//Loop through list to find item
		for (int i = 0; i < l.length(); i++) {
			comp++;
			if (l.getValue() == it) {				//If the current value equals the key
				found = true;						//Boolean variable changed to true
				break;								//End loop
			}
			l.next();								//Change current position to the next element down the list
		}
		//Checks if item is found to set the number of accesses to that item
		if (found == 1)
		{
			int temp = l.getTimes();				//Get current number of accesses of item				
			l.setTimes(temp + 1);					//Set new number of accesses of item				
			reorder();								//Reorder the list
			return true;
		}
		//Else item is new so the item will be inserted at the end of the list
		else {
			l.moveToStart();								//Move to the top of the list
			l.insert(it, 0);								//Call insert function to append item
			return true;
		}
		return false;
	}

	//add(): Adds the new 'it' to the list
	void add(const E& it) {
		l.append(it, 0);								//Calls append function from LList to add item to the list
	}

	//getCompares(): Returns the number of accumulated compares
	int getCompares() const {
		return comp;
	}

	//size(): Returns the size of the list
	int size() const {
		return l.length();
	}

	//printlist(): prints entire list
	void printlist() {
		/*cout << "Move-To-Front Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(l.length()) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/
		l.print(l.length());
	}

	//printlist(): prints n nodes of the  list
	void printlist(int n) {
		/*cout << "Move-To-Front Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(n) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/
		l.print(n);
	}
};