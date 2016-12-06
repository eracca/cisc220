/*Map.hh
*/

#ifndef MAp_HH
#define MAP_HH

#include <string>
#include "EdgeLL.hh"
#include "NodeLL.hh"
#include "Node.hh"

class Map{
    string inFile; 
    NodeLL* nodeList; 
    NodeLL* visitList; 
public:
    Map(string infile);
    ~Map();
    void buildMap(); 
    EdgeLL Djikstra(Node* source);  
};

#endif

