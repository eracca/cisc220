/*Main.cc
*/
//Allan Chandy & Liz Racca
#include "NodeTB.hh"
#include "BSTB.hh"
#include "Game.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	BSTB* test = new BSTB();
	Game* test2 = new Game();
	/*test->insert("babe");
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
	test->printTreeio();
	test->printTreePre();
	test->printTreePost();*/ // Tests BSTB
	test2->startGame();
	system("pause"); // Tests Game
	return 0;

}