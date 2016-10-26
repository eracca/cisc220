/*LLNode.hh
*/

#ifndef LLNODE_HH_
#define LLNODE_HH_

#include <string>

using namespace std;

class LLNode {
    friend class LLPQ;
    friend class LLHuff; 
    char data;
    string code; 
    int count;
    LLNode *next;
    LLNode *left;
    LLNode *right; 
public:
    LLNode(char x, string co="");
    ~LLNode();
    char getData();
};

#endif
