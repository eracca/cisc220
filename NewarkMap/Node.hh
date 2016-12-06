/*Node.hh
*/

#ifndef NODE_HH
#define NODE_HH

#include <string>
#include "EdgeLL.hh"

using namespace std;  

class EdgeLL;

class Node{
    friend class NodeLL;
    string nodeID;
    EdgeLL* edgeFrom;
    int tentDist;
    bool isSource; 
    Node* next; 
public:
    Node(string id);
};

#endif
