/*LLNode.cc
*/

#include "LLNode.hh"
#include <iostream>
#include <stdlib.h>

using namespace std;

LLNode::LLNode(char k, int co) {
    data = k;
    code= co;  
    count=1; 
    next = NULL;
    prev = NULL;
    left = NULL;
    right = NULL;
}

LLNode::~LLNode() {
    if (next != NULL || prev != NULL) {
        cout << "deleting this LLNode may cause a memory leak" << endl;
        }
}

char LLNode::getData() {
    return data;
}
