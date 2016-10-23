/*LLNode.hh
*/

#ifndef LLNODE_HPP_
#define LLODE_HPP_

class LLNode {
    friend class LLPQ;
    char data;
    char[] code; 
    int count;
    LLNode *next;
    LLNode *left;
    LLNode *right; 
public
    LLNode(char x);
    ~LLNode();
    char getData();
};

#endif
