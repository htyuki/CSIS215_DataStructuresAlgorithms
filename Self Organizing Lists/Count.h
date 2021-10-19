/*
* File:   Count.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/
#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

template <typename E>
class Count : public SelfOrderedListADT<E> {
private:
	LList<E> l;
	int comp;
	int counter;
	
public:
	//Constructor
	Count() {
		comp = 0;									//initialize number of comparisons to zero
		counter = 0;
	}
	//Destructor
	~Count() {}

	//reorder: Reorders list items based on the number of times accessed
	void reorder() {
		int moveItem = l.getTimes();					//Assign variable of an item to be moved to the number of access of the item
		l.prev();										//Go to the previous element in the list
		int prevItem = l.getTimes();					//Assign variable of previous item to the number of accesess of the item
		//Loop through items until the number of access of the current item is less than the previous item
		while (moveItem > prevItem) {
			counter = l.getCount();
			l.next();									//Move to the next item
			E temp = l.remove();						//Create temp object that holds the removed item
			l.setTimes(prevItem);						//Set the number of accesses for the item to the previous item
			l.prev();									//Shift down on the list
			l.insert(temp, counter);								//Insert the removed item
			l.setTimes(moveItem);						//Set the number of accesses to the inserted item
			l.next();									//Move forward on the list
			l.setTimes(prevItem);							//Set the number of accesses
			l.prev();									//Go back two times in the list
			l.prev();
			prevItem = l.getTimes();					//Grab the number of accesses

		}
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
		if (found == true)
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
		l.append(it, counter);								//Calls append function from LList to add item to the list
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
		/*cout << "Count Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(l.length()) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/

		l.print(l.length());
	}

	//printlist(): prints n nodes of the  list
	void printlist(int n) {
		/*cout << "Count Heuristic:" << endl;
		cout << "The number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << l.print(n) << endl;
		cout << "My list size is: " << size() << endl;
		cout << endl;*/

		l.print(n);
	}
};