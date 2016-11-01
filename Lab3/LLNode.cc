/*LLNode.cc
*/

#include "LLNode.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

LLNode::LLNode(char k, string co) {
    data = k;
    code= co; 
    count=1; 
    next = NULL;
    left = NULL;
    right = NULL;
}

LLNode::~LLNode() {
    if (next != NULL) {
        cout << "deleting this LLNode may cause a memory leak" << endl;
        }
}

char LLNode::getData() {
    return data;
}
