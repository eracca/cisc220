/*NodeLL.cc
*/

#include "NodeLL.hh"
#include "Node.hh"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

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

void NodeLL::addNode(Node* n){
    if (size == 0){
        first = n;
        last = n; 
        n->next = NULL;  
        size++; 
        return;  
    }
    n->next = first; 
    first = n; 
    size++;
    return;  
}

Node* NodeLL::removeNode(Node* n){
    if (first == n && last == n){
        first = NULL;
        last = NULL;
        size--; 
        return n;
    }
    if (n == first){
        first = n->next;  
        size--; 
        return n; 
    }
    Node* tmp = first;
    while (tmp->next != n){
        tmp = tmp->next; 
    }
    tmp->next = n->next;  
    size--; 
    if (n == last){
        last = tmp; 
    }
    return n; 
}
    
Node* NodeLL::findMin(){
    //find unvisited node with min tentative distance
    //-1 should be treated as infinity
    Node* min = first; 
    while (min != NULL && min->tentDist == -1){
        min=min->next; 
    }
    if (min == NULL){
        return NULL;
    }
    Node* tmp = min; 
    while (tmp->next != NULL){
        tmp = tmp->next; 
        if (tmp->tentDist != -1 && tmp->tentDist < min->tentDist){
            min =  tmp; 
        }
    }
    return min; 
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

Node* NodeLL::findNode(string n){
    Node* tmp = first; 
    while (tmp != NULL){
        if (tmp->nodeID == n){
            return tmp;
        }
        tmp = tmp->next; 
    }
    return NULL;
}
