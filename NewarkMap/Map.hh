/*Map.hh
*/

#ifndef MAp_HH
#define MAP_HH

#include <string>
#include "EdgeLL.hh"
#include "NodeLL.hh"
#include "Node.hh"
#include <vector>
#include <typeinfo>

typedef vector< vector<string> > csvVector; 

class Map{
    string inFile; 
    csvVector csvData; 
    NodeLL* nodeList; 
    NodeLL* visitList; 
public:
    Map(string infile);
    ~Map();
    void buildMap(); 
    void readCSV(); 
    EdgeLL* Djikstra(Node* source);  
};

#endif

