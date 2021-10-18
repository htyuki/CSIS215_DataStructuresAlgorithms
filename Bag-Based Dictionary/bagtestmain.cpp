/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*/

#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 20;

void PauseScreen(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/
int main(int argc, char** argv) {

	cout << "Hayley Yukihiro -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention 
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	cout << "ABag.h Function Tests" << endl;
	cout << endl;
	{
		ABag<KVpair<int, string>> myBag = ABag<KVpair<int, string>>(12);			//Used to test bag functions not previously demonstrated, assigns capacity to 12
		KVpair<int, string> test1 = KVpair<int, string>(1, "String Cheese");		//Test key and value pair to test bag functions
		KVpair<int, string> test2 = KVpair<int, string>(2, "Chex Mix");				//Test key and value pair
		KVpair<int, string> test3 = KVpair<int, string>(3, "Cereal");				//Test key and value pair
		KVpair<int, string> test4 = KVpair<int, string>(4, "Peanuts");				//Test key and value pair
		KVpair<int, string> test5 = KVpair<int, string>(5, "Candy");			    //Test key and value pair
		KVpair<int, string> test6 = KVpair<int, string>(6, "Sunkist Gummies");		//Test key and value pair
		KVpair<int, string> test7 = KVpair<int, string>(7, "Granola");				//Test key and value pair
		KVpair<int, string> test8 = KVpair<int, string>(8, "Almonds");				//Test key and value pair
		KVpair<int, string> test9 = KVpair<int, string>(9, "Fruit");				//Test key and value pair
		KVpair<int, string> test10 = KVpair<int, string>(10, "Vegetables");			//Test key and value pair
		KVpair<int, string> test11 = KVpair<int, string>(11, "Tea");					//Test key and value pair
		KVpair<int, string> test12 = KVpair<int, string>(12, "Coffee");				//Test key and value pair
		KVpair<int, string> test13 = KVpair<int, string>(13, "Hair Brush");          //Test Key and value pair

		//Test addItem
		cout << "Test: addItem" << endl;
		cout << "The bag has 1 item: (should be 1) " << myBag.addItem(test1) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 2 items: (should be 1) " << myBag.addItem(test2) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 3 items: (should be 1) " << myBag.addItem(test3) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 4 items: (should be 1) " << myBag.addItem(test4) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 5 items: (should be 1) " << myBag.addItem(test5) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 6 items: (should be 1) " << myBag.addItem(test6) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 7 item: (should be 1) " << myBag.addItem(test7) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 8 items: (should be 1) " << myBag.addItem(test8) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 9 items: (should be 1) " << myBag.addItem(test9) << endl;			//Output that one item is added by the addItem function call
		cout << "The bag has 10 items: (should be 1) " << myBag.addItem(test10) << endl;		//Output that one item is added by the addItem function call
		cout << "The bag has 11 items: (should be 1) " << myBag.addItem(test11) << endl;		//Output that one item is added by the addItem function call
		cout << "The bag has 12 items: (should be 1) " << myBag.addItem(test12) << endl;		//Output that one item is added by the addItem function call
		cout << "The bag is full: (should be 0) " << myBag.addItem(test13) << endl;				//Output that zero items were added because the bag is full
		cout << endl;

		//Test capacity
		cout << "Test: capacity" << endl;
		cout << "Should be 12: " << myBag.bagCapacity() << endl;     //Output the current maximum capacity of the bag which is 12
		cout << endl;

		//Test size
		cout << "Test: size" << endl;
		cout << "Should be 12: " << myBag.size() << endl;           //Outputs the amount of items in the bag which should be 12
		cout << endl;

		//Test inspectTop
		cout << "Test: inspectTop" << endl;
		cout << "Should be 1 item on top: "<<myBag.inspectTop(test12) << endl;		//Outputs that one item is detected on top
		cout << "Should be Coffee: " << test12.value() << endl;						//Outputs that the top item is the sixth item added which is Coffee
		cout << endl;

		//Test find
		cout << "Test: find" << endl;
		KVpair<int, string> lostValue = KVpair<int, string>(3, "Cereal");								    //KV pair that needs to be found
		KVpair<int, string> lostKey = KVpair<int, string>(6, "Sunkist Gummies");							//KV pair that needs to be found
		KVpair<int, string> lostBrush = KVpair<int, string>(13, "Oh where is my hairbrush . . .");			//KV pair that needs to be found
		cout << "Find Cereal?" << endl;
		cout << "Should be 1 item found: " << myBag.find(lostValue) << endl;								//Outputs that it found the 1 item
		cout << "Should be Cereal: " << lostValue.value() << endl;											//Outputs the key's value which should be Cereal
		cout << "Find Key for Sunkist Gummies?" << endl;													
		cout << "Should be 1 item found: " << myBag.find(lostKey) << endl;									//Outputs that it found the 1 item
		cout << "Should be 6: " << lostKey.key() << endl;													//Outputs the value's key which should be Sunkist Gummies
		cout << "Find Key for Hairbrush?" << endl;
		cout << "Should be 0 item found: " << myBag.find(lostBrush) << endl;								//Outputs that it found 0 item
		cout << "Nobody needs 13 items in this bag: " << lostBrush.key() << endl;							//Outputs the value's key for good measure
		cout << "Find Hairbrush?" << endl;
		cout << "Should be 0 item found: " << myBag.find(lostBrush) << endl;								//Outputs that it found no items in the bag that matched the key
		cout << "Tell Larry that ain't nobody found your hairbrush: " << lostBrush.value() << endl;			//Outputs the key's value which is nowhere in the bag but wanted to be weird for good measure
		cout << endl;
		
		//Test removeTop
		cout << "Test: removeTop" << endl;
		cout << "Should be 1 item to be removed from top: " << myBag.removeTop(test12) << endl;				//Outputs that one item was removed from the top
		cout << "Is the key 12: " << test12.key() << endl;													//Outputs the removed item's key which should be 12
		cout << "Is the value Coffee: " << test12.value() << endl;											//Outputs the removed item's value which should be Coffee
		cout << "Bag should now be 11: " << myBag.size() << endl;											//Outputs the current item count in the bag to check the item was removed
		cout << endl;

		//Test operator+=
		cout << "Test: operator+=" << endl;
		KVpair<int, string> hiccup = KVpair<int, string>(15, "Talking Fishbone");							//Key and Value pair to be added to the bag
		myBag += hiccup;																				    //Uses the += operator to add the new item to the bag
		cout << "Should be 1 item added to the bag: " << myBag.inspectTop(test1) << endl;					//Checks if one item was added on top of the bag
		cout << "Key of new item: " << test1.key() << endl;													//Outputs the key of the new item on top which should be 15
		cout << "Value of new item: " << test1.value() << endl;												//Outputs the value of the new item on top which should be Talking Fishbone
		cout << "Should have 12 items in the bag: " << myBag.size() << endl;								//Checks if the bag updated its item count from 11 to 12
		cout << endl;

		//Test remove
		cout << "Test: remove" << endl;
		cout << "Should be 1 item removed: " << myBag.remove(test8) << endl;						//Outputs that one item is identified to be removed by the function call and its parameter
		cout << "Key should be 8: " << test8.key() << endl;											//Checks the key of the found item to be removed which shuld be 8
		cout << "Value should be Almonds: " << test8.value() << endl;								//Checks the value of the found item to be removed which should be Almonds
		cout << "Should be 11 items in the bag: " << myBag.size() << endl;							//Checks that the current bag item count was updated from 12 to 11
		cout << endl;

		//Test emptyBag
		cout << "Test: emptyBag" << endl;
		myBag.emptyBag();																			//Calls function to empty items in the bag
		cout << "Current item count in bag should be zero: " << myBag.size() << endl;				//Checks the current item count in the bag which should be 0
		cout << endl;
	}
	PauseScreen();

	return 0;
}

//Used to pause the screen wherever desired
void PauseScreen()
{
	char ch;
	cout << "\nPress the Enter key to continue ... ";
	cin.get(ch);
}
