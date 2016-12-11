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

    //select node as source node and 3 target nodes to test
    Node* source = m->nodeList->findNode("170139186518"); 
    Node* t1 = m->nodeList->findNode("171635186792"); 
    Node* t2 = m->nodeList->findNode("170259185821"); 
    Node* t3 = m->nodeList->findNode("171699187388"); 

    //run Djikstra on the source
    m->Djikstra(source); 

    //find path to targets, print paths
    EdgeLL* p1 = m->findPath(t1);
    EdgeLL* p2 = m->findPath(t2);
    EdgeLL* p3 = m->findPath(t3);
    cout << "path 1:" << endl;  
    p1->printEdges();
    cout << "path 2:" << endl;  
    p2->printEdges();
    cout << "path 3:" << endl;  
    p3->printEdges();
    return 0; 
}
