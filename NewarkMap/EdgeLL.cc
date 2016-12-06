/*EdgeLL.cc
*/

#include "EdgeLL.hh"
#include "Edge.hh"

EdgeLL::EdgeLL(){
    first = NULL;
    last = NULL;
    size = 0; 
}

EdgeLL::~EdgeLL(){
}

void EdgeLL::addFirst(Edge* e){
    first = e;
    last = e; 
    size++; 
}

void EdgeLL::addEdge(Edge* e){
    if (first == NULL){
        addFirst(e); 
    }
    else{
        e->next = first; 
        first = e; 
        size++;
    }
}

