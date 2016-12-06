/*
Edge.hh
*/

#ifndef EDGE_HH
#define EDGE_HH

#include <string>
#include "Node.hh"

using namespace std;  

class Node; 

class Edge{
    string objectID;
    string name; 
    Node* fNode;
    Node* tNode;
    int length;
    Edge* next; 
public:
    Edge(string id, Node* fro, Node* to, int l); 
    ~Edge(); 
};

#endif
