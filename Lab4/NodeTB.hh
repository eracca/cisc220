/*NodeTB.hh
*/

#ifndef NODETB_HH_
#define NODETB_HH_

#include <string> 

class NodeTB {
    friend class BSTB; 
    NodeTB *left;
    NodeTB *right; 
    string word; 
public:
    NodeTB(string w); 
    ~NodeTB(); 
}

#endif
