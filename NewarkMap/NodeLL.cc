/*NodeLL.cc
*/

#include "NodeLL.hh"
#include "Node.hh"
#include <string>
#include <iostream>

using namespace std;  

NodeLL::NodeLL(){
    first = NULL;
    last = NULL;
    size = 0; 
}
Node* NodeLL::addFirst(string id){
    Node* n = new Node(id);  
    first =  n;
    last = n;
    size++; 
    return first;  
}
Node* NodeLL::addNode(string id){
    if (first == NULL){
        return addFirst(id);
    }
    else{
        Node* tmp = first;  
        while (tmp != NULL){
            if (tmp->nodeID == id){
                return tmp; //don't add if its already in there
            }
            tmp = tmp->next;
        }
        Node* n = new Node(id);
        last->next = n; 
        last =  n; 
        size++; 
        return last;  
    }
}

void NodeLL::printNodeLL(){
    if (first == NULL){
        cout << "nothing here" << endl;  
        return;
    }
    Node* tmp = first; 
    while (tmp != NULL){
        tmp->edgeFrom->printEdges();
        tmp = tmp->next; 
    }
}

