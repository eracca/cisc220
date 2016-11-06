/*Main.cc
*/

#include "NodeTB.hh"
#include "BSTB.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	BSTB* test = new BSTB();
	test->insert("babe");
	test->insert("rest");
	test->insert("wanton");
	test->insert("wanton");
	test->insert("shawn");
	test->insert("dunce");
	test->insert("fabric");
	test->insert("deject");
	test->insert("chars");
	test->insert("master");
	cout << "I added some words!" << endl;
	cout << test->height() << endl;	
	test->adjustBalances();
	cout << test->height() << endl;
	test->printTreeio();
	test->printTreePre();
	test->printTreePost();
	system("pause");
	return 0;
}