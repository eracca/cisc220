/*EdgeLL.hh
*/

#ifndef EDGELL_HH
#define EDGELL_HH

#include "Edge.hh"

class Edge;

class EdgeLL{
    Edge* first; 
    int size; 
public:
    EdgeLL();
    ~EdgeLL(); 
    void addEdge(Edge* e);
};

#endif
