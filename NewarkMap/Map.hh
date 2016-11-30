/*Map.hh
*/

#ifndef MAp_HH
#define MAP_HH

#include <string>
#include "EdgeLL.hh"
#include "Node.hh"

class Map{
    string inFile; 
    Node* nodeList; 
    Node* visitList; 
public:
    Map(string infile);
    ~Map();
    void buildMap(); 
    EdgeLL Djikstra(Node* source);  
};

#endif

