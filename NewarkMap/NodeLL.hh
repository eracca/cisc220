/*NodeLL.hh
*/

#ifndef NODELL_HH
#define NODELL_HH

#include "Node.hh"
#include <string>

using namespace std; 

class NodeLL{
    Node* first;
    Node* last; 
public:
    NodeLL();  
    Node* addFirst(string id);
    Node* addNode(string id); 
    void addNode(Node* n); 
    Node* removeNode(Node* n); 
    void printNodeLL();
    Node* findMin(); 
    Node* randNode(); 
    int size; 
};

#endif
