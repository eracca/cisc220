/*Map.cc
*/

#include "Map.hh"
#include "EdgeLL.hh"
#include "Edge.hh"
#include "Node.hh"

Map::Map(string f){
    inFile = f; 
    nodeList = new NodeLL(); 
    buildMap(); 
}
void Map::buildMap(){
    //read infile
    //get line
    //pull out each line and get the toNode and the fromNode data
    //if fromNode not in list of nodes, make a new node
    //make a new edge in the fromNode EdgeLL
    //if not one way, make edge opposite direction
}
EdgeLL Map::Djikstra(Node* source){
}
