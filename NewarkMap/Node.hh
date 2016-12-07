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
    friend class Edge;
    int tentDist;
    bool isSource; 
    Node* next; 
public:
    Node(string id);
    EdgeLL* edgeFrom;
    string nodeID;
};

#endif
