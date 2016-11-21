/*NodeTB.cc
*/

<<<<<<< HEAD
//Allan Chandy & Liz Racca
=======
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
#include "NodeTB.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

<<<<<<< HEAD
NodeTB::NodeTB(string w) {
	word = w;
	left = NULL;
	right = NULL;
	parent = NULL;
}
NodeTB::~NodeTB() {
	if (left != NULL || right != NULL) {
		cout << "deleting this NodeTB may cause a memory leak" << endl;
	}
};
=======
NodeTB::NodeTB(string w){
    word = w;
    left = NULL;
    right = NULL; 
    parent = NULL; 
}
NodeTB::~NodeTB(){
    if (left != NULL || right != NULL){
        cout << "deleting this NodeTB may cause a memory leak" << endl; 
    }
};
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
