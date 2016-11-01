/*NodeTB.cc
*/

#include "NodeTb.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std; 

void NodeTB::NodeTB(string w){
    word = w;
    left = NULL;
    right = NULL; 
}
void NodeTB::~NodeTB(){
    if (left != NULL || right != NULL){
        cout << "deleting this NodeTB may cause a memory leak" << endl; 
    }
}
