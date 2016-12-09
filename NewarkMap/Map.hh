/*Map.hh
*/

#ifndef MAp_HH
#define MAP_HH

#include <string>
#include <vector>
#include "EdgeLL.hh"
#include "NodeLL.hh"
#include "Node.hh"

class Map{
    string filename; 
    NodeLL* nodeList; 
    NodeLL* visitList; 
public:
    Map(string infile);
    ~Map();
    void buildMap(); 
    EdgeLL* Djikstra(Node* source);  
    void split(const string &s, char delim, vector <string> &elems);
};

#endif

