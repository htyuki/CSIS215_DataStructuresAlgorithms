/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Hayley Yukihiro
* CSIS215 - D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Shaffer
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"


template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	//Constructor
	BDictionary(int size = 20)
	{
		dictionary = new ABag<KVpair<Key, E>>(size);      //Instantiates the dictionary
	}
	//Destructor
	~BDictionary()
	{
		delete dictionary;								//Destructs the dictionary
	}

	//clear: Reinitialize dictionary
	void clear()
	{
		dictionary->emptyBag();							//Reinitializes the dictionary by calling the emptyBag function
	}

	//insert: Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e)
	{
		KVpair<Key, E> temp(k, e);									//Create temporary pair
		bool trueInsert = dictionary->addItem(temp);			    //Assign the bool variable to the addItem function call of the temporary pair for insert
		if (trueInsert)									           //Checks if the insertion is true or false 
		{
			return trueInsert;										//If insertion is true, it will return true
		}
		else
			cout << "Unable to insert record" << endl;				//IF it returns false, it will output an error message
	}

	//remove: Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal)
	{
		KVpair<Key, E> temp(k, rtnVal);                            //Temporary pair
		bool goodRemove = dictionary->remove(temp);				   //Assign to bool variable to call the remove function of the temporary pair for removal
		if (goodRemove)                                            //Checks if there was a good removal of the reord
		{
			rtnVal = temp.value();                                 //Updates the rtnVal
			return goodRemove;									   //Return true if record is removed
		}
		else
			cout << "Unable to remove record" << endl;				//Return false if record cannot be removed

	}

	//removeAny: Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue)
	{
		Key k = keyTemp;
		KVpair<Key, E> temp(k, returnValue);								//Created a temperoray value
		bool isRemove = dictionary->removeTop(temp);					    //Assign to bool variable to call the removeTop function for removal of record
		if (isRemove)													   //Tests if removal was true
		{
			returnValue = temp.value();								    //Updates the returnValue
			return isRemove;											//Return true if record is removed
		}
		else
			cout << "Unable to remove arbitrary record" << endl;		//return false if record cannot be removed
	}
	
	//find: Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> temp(k, returnValue);                        //Created a temporary pair
		bool goodFind = dictionary->find(temp);                     //Assign to bool variable to call the find function for finding the record 
		if (goodFind)												//Checks if record could be found
		{
			returnValue = temp.value();						       //Updates the return value
			return goodFind;										//Returns true if record is found
		}
		else
			cout << "Unable to find record" << endl;				//Returns false if record cannot be found
	}

	//size: Return the number of records in the dictionary.
	int size()
	{
		return dictionary->size();                         //Call size function to return the number of records
	}
	

private:
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the 
	//functions you need to build your dictionary.
	ABag<KVpair<Key, E>>* dictionary;
	Key keyTemp;
};


#endif	/* BDICTIONARY_H */

