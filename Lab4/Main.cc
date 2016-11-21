/*Main.cc
*/
<<<<<<< HEAD
//Allan Chandy & Liz Racca
=======

>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
#include "NodeTB.hh"
#include "BSTB.hh"
#include "Game.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

<<<<<<< HEAD
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
=======
using namespace std; 

int main(){
    Game* g1 = new Game("testdict.txt"); 
    g1->startGame(); 
    return 0; 
}
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
