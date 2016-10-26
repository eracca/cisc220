/*LLNode.hh
*/

#ifndef LLNODE_HH_
#define LLNODE_HH_

#include <string>

using namespace std;

class LLNode {
    friend class LLPQ;
    friend class LLHuff; 
public:
    char data;
    string code; 
    int count;
    LLNode *next;
    LLNode *left;
    LLNode *right; 
    LLNode(char x, string co="");
    ~LLNode();
    char getData();
};

#endif
