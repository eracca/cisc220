/*Node.cc
*/

#include "Node.hh"
#include "Edge.hh"
#include "EdgeLL.hh"
#include <string>

using namespace std; 

Node::Node(string id){
    nodeID = id; 
    edgeFrom = new EdgeLL(); 
    tentDist = -1; 
    isSource = false;
    next = NULL;
    pathEdge = NULL;  
};
