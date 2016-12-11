/*Edge.cc
*/

#include <string>
#include <stdlib.h>
#include "Edge.hh"
#include "Node.hh"

Edge::Edge(string id, string n, Node* fro, Node* to, int l){
    objectID = id; 
    name = n; 
    fNode = fro; 
    tNode = to; 
    length = l; 
    next = NULL;
}

