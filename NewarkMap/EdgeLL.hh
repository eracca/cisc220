/*EdgeLL.hh
*/

#ifndef EDGELL_HH
#define EDGELL_HH

#include "Edge.hh"

class Edge;

class EdgeLL{
    Edge* first; 
    Edge* last;
    int size; 
public:
    EdgeLL();
    ~EdgeLL(); 
    void addFirst(Edge* e); 
    void addEdge(Edge* e);
};

#endif
