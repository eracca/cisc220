/*EdgeLL.cc
*/

#include "EdgeLL.hh"
#include "Edge.hh"
#include <stdlib.h>
#include <iostream>

using namespace std;

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

void EdgeLL::printEdges(){
    if (first == NULL){
        return;
    }
    Edge* tmp = first; 
    while (tmp != NULL){
        cout << "id: " << tmp->objectID << "  name: " << tmp->name 
        << "  from: " << tmp->fNode->nodeID << "  to: " << tmp->tNode->nodeID
        << "  length: " << tmp->length << endl;
        tmp=tmp->next; 
    }
}

void EdgeLL::updateDist(){
    Edge* tmp = first;  
    while (tmp != NULL){
        if (tmp->tNode->tentDist == -1 || 
            (tmp->fNode->tentDist + tmp->length) < tmp->tNode->tentDist){
            tmp->tNode->tentDist = tmp->fNode->tentDist + tmp->length;
            cout << "new path edge " <<tmp->tNode->pathEdge->objectID << endl; 
        }
        tmp = tmp->next; 

    }
}

