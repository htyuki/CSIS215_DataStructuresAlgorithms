/*
* File:   Transpose.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/
#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

template <typename E>
class Transpose : public SelfOrderedListADT<E> {
private:
	LList<E> l;
	int comp;
	int counter; 

public:
	//Constructor
	Transpose() {
		comp = 0;										//initialize number of comparisons to zero
		counter = 0;
	}
	//Destructor
	~Transpose() {}

	//reorder: Reorders list items by swapping them with a previous item
	void reorder() {
		 E headItem = l.headValue();						//Variable that has the first item of the list
		 E tailItem = l.tailValue();						//Variable that has the last item of the list
		 counter = l.getCount();
		
		//If the current item matches the first item and it returns
		if (l.getValue() == headItem) {
			return;										
		}

		//If the current item matches the last item
		if (l.getValue() == tailItem) {
			int tailItem = l.getTimes();				//Gets the number of acccess times for the last item in the list
			l.prev();									//Goes back one item
			int prevItem = l.getTimes();				//Gets the number of access times for the previous item in the list
			E temp = l.remove();						//Remove the previous element and put it in a temp object
			l.setTimes(prevItem);						//Updates access times for previous item
			l.moveToEnd();								//Go to end of the list
			l.insert(temp, counter);								//Insert removed item
			l.setTimes(prevItem);						//Update number of access times for inserted item
			l.prev();									//Go back one item in the list
			l.setTimes(tailItem);						//Update number of access times for end item
			return;
		}

		int moveItem = l.getTimes();					//Assign variable of an item to be moved
		l.prev();										//Go to the previous element in the list
		int prevItem = l.getTimes();					//Assign variable of previous item to the number of accesess of the item
		l.next();										//Go back to the item being moved
		int currItem = l.getTimes();					//Get number of access times for that value previous in the list
		l.next();										//Advance the list
		int nextItem = l.getTimes();					//Get number of access times for that value next in the list
		l.prev();										//Go back to the item to be removed
		E temp = l.remove();							//Remove item
		l.setTimes(nextItem);							//Update number of accesses
		l.prev();										//Go back in the list
		prevItem = l.getTimes();						//Get number of accesses
		l.insert(temp, counter);									//Insert the removed value
		l.setTimes(moveItem);							//Update the number of access times for removed value
		l.next();										//Advance the list
		l.setTimes(prevItem);							//Update access times
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
			add(it);								//Call add function to append item
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
		/*cout << "Transpose Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(l.length()) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/
		l.print(l.length());
	}

	//printlist(): prints n nodes of the  list
	void printlist(int n) {
		/*cout << "Transpose Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(n) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/
		l.print(n);

	}
};