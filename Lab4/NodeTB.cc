/*NodeTB.cc
*/

#include "NodeTB.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std; 

NodeTB::NodeTB(string w){
    word = w;
    left = NULL;
    right = NULL; 
}
NodeTB::~NodeTB(){
    if (left != NULL || right != NULL){
        cout << "deleting this NodeTB may cause a memory leak" << endl; 
    }
};
