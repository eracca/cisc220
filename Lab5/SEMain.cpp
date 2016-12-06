/*
* SEMain.cpp
*
*  Created on: Nov 8, 2016
*      Author: Debra
*/

#include "Document.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	//insertion sort
	Document doc0("Monet.txt");
	doc0.readFile();
	cout << "WORDLIST" << endl;
	doc0.wordlist->printLL();
	cout << endl << endl;
	doc0.pickSort(0);
	cout << endl << endl;

	//quicksort
	Document doc1("Monet.txt");
	doc1.readFile();
	doc1.pickSort(1);
	cout << endl << endl;

	//heapsort
	Document doc2("Monet.txt");
	doc2.readFile();
	doc2.pickSort(2);
	cout << endl << endl;
	return 0;
}
