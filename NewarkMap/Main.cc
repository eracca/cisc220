/*Main.cc
*/

#include <stdlib.h>
#include <iostream>
#include "Edge.hh"
#include "EdgeLL.hh"
#include "NodeLL.hh"
#include "Node.hh"
#include <string>

using namespace std;

int main(){
    NodeLL* nodeList = new NodeLL();
    Node* fro = nodeList->addNode("169963187334");
    Node* to = nodeList->addNode("170055187289");
    Edge* e = new Edge("365", "MAIN", fro, to, 102); 
    fro->edgeFrom->addEdge(e); 
    nodeList->printNodeLL();
    return 0; 
}
