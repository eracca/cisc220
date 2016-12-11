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
#include <time.h>

using namespace std;

int main(){
    Map* m = new Map("mapdata.csv"); 
    cout << "read map" << endl; 
    //generate random source nodes and 3 target nodes for testing
    Node* source = m->nodeList->randNode(); 
    Node* t1 =  m->nodeList->randNode();
    Node* t2 =  m->nodeList->randNode();
    Node* t3 =  m->nodeList->randNode();
    cout << source->nodeID << endl; 
    cout << "made nodes" << endl;

    m->Djikstra(source); 

    cout << "did Djikstra" <<  endl; 
    m->nodeList->printNodeLL(); 
    m->visitList

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
