/*NodeTB.hh
*/

#ifndef NODETB_HH_
#define NODETB_HH_

#include <string> 

using namespace std;

class NodeTB {
    friend class BSTB; 
    NodeTB *left;
    NodeTB *right; 
    NodeTB *parent; 
    string word; 
public:
    NodeTB(string w); 
    ~NodeTB(); 
};

#endif
