/*Main.cc
*/

#include <stdlib.h>
#include <iostream>
#include "Map.hh"
#include "Edge.hh"
#include "EdgeLL.hh"
#include "NodeLL.hh"
#include "Node.hh"
#include <string>

using namespace std;

int main(){
    //build map using csv data file
    Map* m = new Map("mapdata.csv"); 
    cout << "read map" << endl; 

    //select node as source node and a target node to test
    Node* source = m->nodeList->findNode("170139186518"); 
    Node* t1 = m->nodeList->findNode("170259185821"); 

    //run Djikstra on the source
    m->Djikstra(source); 

    //find path to target, print path
    EdgeLL* p1 = m->findPath(t1);
    cout << "path:" << endl;  
    p1->printEdges();
    return 0; 
}
