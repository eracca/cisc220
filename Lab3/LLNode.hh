/*LLNode.hh
*/

#ifndef LLNODE_HPP_
#define LLODE_HPP_

class LLNode {
    friend class LLPQ;
    char data;
    int code; 
    int count;
    LLNode *next;
    LLNode *prev;
    LLNode *left;
    LLNode *right; 
public
    LLNode(char x);
    ~LLNode();
    char getData();
};

#endif
