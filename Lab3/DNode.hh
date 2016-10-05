/*DNode.hh
*/

#ifndef DNODE_HPP_
#define DNODE_HPP_

class DNode {
    friend class LLPQ;
    char data;
    int code; 
    int count;
    DNode *next;
    DNode *prev;
    Dnode *left;
    Dnode *right; 
public
    DNode(char x);
    ~DNode();
    char getData();
};

#endif
