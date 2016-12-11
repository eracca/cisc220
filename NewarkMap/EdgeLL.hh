/*EdgeLL.hh
*/

#ifndef EDGELL_HH
#define EDGELL_HH

#include "Edge.hh"

class Edge;

class EdgeLL{
    friend class Node;
    Edge* first; 
    Edge* last;
    int size; 
public:
    EdgeLL();
    void addFirst(Edge* e); 
    void addEdge(Edge* e);
    void printEdges(); 
    void updateDist(); 
    
};

#endif
