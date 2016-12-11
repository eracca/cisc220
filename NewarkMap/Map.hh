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
    Node* source; 
public:
    Map(string infile);
    void buildMap(); 
    void Djikstra(Node* source);  
    void split(const string &s, char delim, vector <string> &elems);
    EdgeLL* findPath(Node* target); 
    NodeLL* nodeList; 
    NodeLL* visitList; 
};

#endif

