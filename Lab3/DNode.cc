/*DNode.cc
*/

#include "DNode.hh"
#include <iostream>
#include <stdlib.h>

using namespace std;

DNode::DNode(char k) {
    data = k;
    code=NULL; 
    count=0; 
    next = NULL;
    prev = NULL;
    left = NULL;
    right = NULL;
}

DNode::~DNode() {
    if (next != NULL || prev != NULL) {
        cout << "deleting this DNode may cause a memory leak" << endl;
        }
}

char DNode::getData() {
    return data;
}
