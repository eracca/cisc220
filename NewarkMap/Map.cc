/*Map.cc
*/

#include "Map.hh"
#include "EdgeLL.hh"
#include "Edge.hh"
#include "Node.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include "stdlib.h"

Map::Map(string f){
    filename = f; 
    nodeList = new NodeLL(); 
    buildMap(); 
}
void Map::buildMap(){
    string line; 
    ifstream csv; 
    const char *f = filename.c_str();  
    csv.open(f); 
    while (!csv.eof()){    
        getline(csv, line);
        if (!csv.eof()){
            vector<string> linedata;
            split(line, ',', linedata);
            Node* fnode = nodeList->addNode(linedata[4]);
            Node* tnode = nodeList->addNode(linedata[5]);
            int l = atoi(linedata[1].c_str());
            Edge* e = new Edge(linedata[0], linedata[2], fnode, tnode, l);
            fnode->edgeFrom->addEdge(e);
            if (linedata[3]=="n"){
                Edge* e2 = new Edge(linedata[0], linedata[2], tnode, fnode, l);
                tnode->edgeFrom->addEdge(e2); 
            }
        }
    }
    nodeList->printNodeLL();  
}

void Map::split(const string &s, char delim, vector <string> &elems){
    stringstream ss;
    ss.str(s);
    string item;
    while(getline(ss, item, delim)){
        elems.push_back(item);
    }
}

void Map::Djikstra(Node* s){
    source = s;
    visitList = new NodeLL(); 
    source->isSource = true; 
    source->tentDist = 0;  
    Node* visitNode = source; 
    while (nodeList->size != 0){
        visitNode->edgeFrom->updateDist();
        visitList->addNode(nodeList->removeNode(visitNode));
        visitNode = nodeList->findMin(); 
        if (visitNode == NULL){
            return;
        }
    } 
}

EdgeLL* Map::findPath(Node* target){
    EdgeLL* path = new EdgeLL();
    Edge* e = target->pathEdge; 
    if (e == NULL){
        cout << "e is null " << endl;
    }
    while (e != NULL){
        path->addEdge(e); 
        cout << "id: " << e->objectID << " fNode: " << e->fNode->nodeID 
        << " tNode: " << e->tNode->nodeID << endl;
        e = e->tNode->pathEdge;
    }
    return path; 
}
