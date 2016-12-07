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
    int size; 
public:
    NodeLL();  
    Node* addFirst(string id);
    Node* addNode(string id); 
    void printNodeLL();
};

#endif
