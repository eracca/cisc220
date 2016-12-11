/*Node.hh
*/

#ifndef NODE_HH
#define NODE_HH

#include <string>
#include "EdgeLL.hh"
#include  "Edge.hh"

using namespace std;  

class Edge;
class EdgeLL;

class Node{
    friend class NodeLL;
    friend class Edge;
    Node* next; 
public:
    Node(string id);
    EdgeLL* edgeFrom;
    string nodeID;
    int tentDist;
    Edge* pathEdge; 
    bool isSource; 
};

#endif
