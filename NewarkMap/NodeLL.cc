/*NodeLL.cc
*/

#include "NodeLL.hh"
#include "Node.hh"
#include <string>

using namespace std;  

NodeLL::Node(){
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
        addFirst(id);
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
