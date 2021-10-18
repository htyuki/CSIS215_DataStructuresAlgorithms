/*
File: Source.cpp -- Main program executable that will produce the required output
Author: Hayley Yukihiro
CSIS215 - D01
ReferenceL A Practical Introduction to Data Structures and Algorithm Analysis by Shaffer
*/

#include <iostream>
#include <string>
#include "../BST.h"

int main()
{
	//Lab title output
	cout << "Hayley Yukihiro -- CSIS 215 Programming Assignment 2 -- Double Threaded Binary Tree" << endl << endl;

	//Insert values into the tree
	BST<int, string> t;
	t.insert(77, "seventy-seven");
	t.insert(70, "seventy");
	t.insert(75, "seventy-five");
	t.insert(66, "sixty-six");
	t.insert(79, "seventy-nine");
	t.insert(68, "sixty-eight");
	t.insert(67, "sixty-seven");
	t.insert(69, "sixty-nine");
	t.insert(90, "ninety");
	t.insert(85, "eighty-five");
	t.insert(83, "eighty-three");
	t.insert(87, "eighty-seven");
	t.insert(65, "sixty-five");

	//Test output
	cout << "Testing the insert function to build my tree." << endl;
	cout << "My BST tree size is " << t.size() << endl;														//Calls the size() function to output the tree size
	cout << "My tree's structure is (tests my changes to the print function): " << endl;
	t.print();																								//Calls the print() function to print out the contents of the tree 
	cout << endl;
	cout << "Inorder printing of my tree (tests my right threads and print Inorder function): " << endl;
	t.printInorder();																						//Calls the printInorder() function to print out the tree contents in order
	cout << endl;
	cout << "Reverse order printing of my tree (tests my left thread and printReverse function)" << endl;
	t.printReverse();																						//Calls the printReverse() function to print out the tree contents in reverse order
	cout << endl;

	system("pause");
	return 0;
}