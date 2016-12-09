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

EdgeLL* Map::Djikstra(Node* source){
}
