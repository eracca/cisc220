/*Main.cc
*/

#include "NodeTB.hh"
#include "BSTB.hh"
#include "Game.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std; 

int main(){
    Game* g1 = new Game("testdict.txt"); 
    g1->startGame(); 
    return 0; 
}
