/*Node.cc
*/

#include "Node.hh"
#include "Edge.hh"
#include "EdgeLL.hh"
#include <string>

using namespace std; 

Node::Node(string id){
    string nodeID = id; 
    EdgeLL* edgeFrom = new EdgeLL(); 
    int tentDist = -1; 
    bool isSource = false;
    next = NULL;
}
