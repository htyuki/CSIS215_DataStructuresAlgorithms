/*
* File:   test.cpp
* Author: Hayley Yukihiro
* CSIS215: D01
* References: A Practical Introduction to Data Structures and Algorithm Analysis by Staffer
*/
#include "llist.h"
#include "Count.h"
#include "Transpose.h"
#include "MoveToFront.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
template <typename E>
void charTest(SelfOrderedListADT<E> &sol, string name, char find[], int length);
template <typename E>
void stringTest(SelfOrderedListADT<E> &sol, string name);

int main()
{
	//Lab title output
	cout << "Hayley Yukihiro -- CSIS 215 Programming Assignment 4 -- Self-Organizing Lists" << endl << endl;
	
	//First Test with char types
	//Constant variables for test list sizes
	const int fS = 14;
	const int S = 8;

	//Non constant variables of list contents
	char starterList[S] = { 'A','B','C','D','E','F','G','H' };
	char findList[fS] = { 'F','D','F','G','E','G','F','A','D','F','G','E','H','I' };
	Count<char> cntC;
	MoveToFront<char> mtfC;
	Transpose<char> trpC;

	//Program Logic
	//Loop to add in characters to the list
	for (int i = 0; i < S; i++) {
		cntC.add(starterList[i]);
		mtfC.add(starterList[i]);
		trpC.add(starterList[i]);
	}

	//Output results
	charTest(cntC, "Count", findList, fS);
	cout << endl;
	charTest(mtfC, "Move-To-Front", findList, fS);
	cout << endl;
	charTest(trpC, "Transpose", findList, fS);
	cout << endl << endl;

	//Second test with txt file to read in string types
	//Non-constant variables for string read in test
	Count<string> cntS;
	MoveToFront<string> mtfS;
	Transpose<string> trpS;

	//Program Logic
	//Read in text file
	ifstream input;
	input.open("test.txt");
	if (!input) {
		cerr << "Unable to open text file";
		exit(1);
	}
	string c;
	//Loop chars into the linked lists
	while (input >> c) {
		cntS.find(c);
		mtfS.find(c);
		trpS.find(c);
	}
	input.close();

	//Output Results
	stringTest(cntS, "Count");
	cout << endl;
	stringTest(mtfS, "Move-To-Front");
	cout << endl;
	stringTest(trpS, "Transpose");
	

	cout << endl << endl;
	system("pause");
	return 0;
}

//charTest function implementation
template <typename E>
void charTest(SelfOrderedListADT<E> &sol, string name, char find[], int length) {
	string output;
	if (name == "Count")
		output = "     F G D E A H B C I and compares should be 61";
	else if (name == "Move-To-Front")
		output = "     I H E G F D A B C and compares should be 70";
	else if (name == "Transpose")
		output = "     A B F D G E H C I and compares should be 78";
	cout << "Testing: " << name << endl;
	cout << "My starting list is: " << endl;
	cout << "      ";
	sol.printlist();
	cout << endl;
	//Loop through looking for chars in find
	for (int i = 0; i < length; i++) {
		sol.find(find[i]);
	}
		cout << "Testing: " << name << ". If correct, my list should be: " << endl;
		cout << output << endl;
		cout << name << " Heuristic:" << endl;
		cout << "The number of compares is: " << sol.getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		sol.printlist();
		cout << endl;
		cout << "My list size is: " << sol.size() << endl;
		cout << endl;
}

//stringTest function implementation
template <typename E>
void stringTest(SelfOrderedListADT<E> &sol, string name) {
	cout << name << " Heuristic" << endl;
	cout << "Size of List: " << sol.size() << endl;
	cout << "Number of compares: " << sol.getCompares() << endl;
	cout << endl;
	sol.printlist(10);
	cout << endl << endl;
}