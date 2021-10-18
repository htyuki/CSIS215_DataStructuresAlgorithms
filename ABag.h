/*
* File:   ABag.h
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/

#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"


template <typename E>
class ABag : public Bag<E> {
public:
	// Constructor
	ABag(int capBag = 20)
	{
		capacity = capBag;				//Set capacity to the max size
		used = 0;						//Set the current number of items in the array to zero
		data = new E[capBag];		   //Establish data as the array of type E with the max size elements
	}

	// Destructor
	~ABag()
	{
		delete[] data;       //Destructs items in the data array
		data = NULL;	    //Fully deletes pointer
	}

	// addItem: Insert a new item into the bag -- return false if fails and true if successful
	bool addItem(const E& item)
	{
		if (used != capacity)			//Checks if bag is not at capacity
		{
			data[used++] = item;	    //adds item to the data array of the bag
			return true;
		}
		else							//Bag is at capacity
		{
			return false;				//Bag will not add the new item
		}
	}

	//remove: Looks for 'item' in the bag and if found updates 'item' with the bag value and returns true.  
	//Otherwise 'item' is left unchanged and the method returns false.
	bool remove(E& item)
	{
		bool foundItem = false;				//Boolean variables that represents the return of false
		for (int i = 0; i < used; i++)		//goes through each item that exist in the bag
		{
			if (data[i] == item)			//checks if the item equals a bag item
			{
				item = data[i];							//updates and sets the item as the list item
				foundItem = true;						//returns true that the item was found in the bag
				for (int j = i + 1; j < used; j++)		//goes back through the bag after the update to shift items
				{
					data[i] = data[j];              //shifts the bag items down        
				}
				used--;                         //decrements the item number in the bag
			}
					
		}
		return foundItem;                      //Returns false and the item is left unchanged if the loop does not find the item in the bag
	}

	//removeTop: Removes the top record from the bag, puts it in returnValue, and returns true if the bag is not empty.  
	//If the bag is empty the function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue)
	{
		if (used != 0)							//Checks if the bag has any items
		{
			data[--used] = returnValue;			//removes the top item and assigns it to returnValye
			return true;						//returns true because the bag is not empty
		}
		else                                //There are no items in the bag
		{
			return false;	                //returns false and returnValue remains unchanged					
		}
	}

	//find: Finds the record using returnValue
	//If the record is found, updates returnValue based on the contents of the bag and returns true
	//If the record is not found the function returns false.  
	//Works just like remove() except that the found record is not removed from the bag.
	bool find(E& returnValue) const
	{
		for (int i = 0; i < used; i++)		//goes through each item that exist in the bag
		{
			if (data[i] == returnValue)			//checks if the returnValue equals a bag item
			{
				returnValue = data[i];						//updates and sets returnValue as the found bag item
				return true;						//returns true that the item was found in the bag
			}
		}
		return false;                          //Returns false if the item is not found in the bag
	}

	//InspectTop: Inspect the top of the bag.  
	//If the bag is empty return false and leave 'item' unchanged; 
	//otherwise, return true and update 'item' with the contents of the bag.
	bool inspectTop(E& item) const
	{
		if (used != 0)							//Checks if the bag has any items
		{
			item = data[used - 1];			//Assigns item to the contents of the bag
			return true;						//returns true because the bag is not empty
		}
		else                                //There are no items in the bag
		{
			return false;	                //returns false and item remains unchanged					
		}
	}

	//emptyBag:empties the bag
	void emptyBag()
	{
		used = 0;           //Sets the item count of the bag to zero
	}

	//operator+=:use the += operator to add an item to the bag
	bool operator+=(const E& addend)
	{
		return addItem(addend);					//returns the addItem function call when += is used to add an item to the bag
	}

	//size:get the size of the bag
	int size() const
	{
		return used;							//returns used which contains the number of current items in bag
	}

	//bag:Capacity:get the capacity of the bag
	int bagCapacity() const
	{
		return capacity;					//returns capacity which contains the size of the bag 
    }

private:
	E *data;            // an array of items
	int used;           // number of items the data array currently holds
	int capacity;       // the number of items the bag can hold (size of array)
};

#endif	/* ABAG_H */

