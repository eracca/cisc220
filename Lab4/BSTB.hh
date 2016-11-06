/*BSTB.hh
*/

#ifndef BSTB_HH_
#define BSTB_HH_

#include "NodeTB.hh"

class BSTB {
    NodeTB *root;
    int count;
public:
    BSTB(); 
    ~BSTB();
    bool insert(string x); 
    bool insert(string x, NodeTB *n);
    void printTreeio(); 
    void printTreeio(NodeTB *n); 
    void printTreePre(); 
    void printTreePre(NodeTB *n); 
    void printTreePost(); 
    void printTreePost(NodeTB *n); 
    bool search(string x); 
    bool search(NodeTB *n, string x); 
	void adjustBalances(NodeTB *n);
	void adjustBalances();
	void delTree(NodeTB *cur);
	int height(NodeTB *n);
	int height();
	NodeTB *rotateRight(NodeTB *n);
    NodeTB *rotateLeft(NodeTB *n); 
	int getScore(BSTB *dict); 
    int getScore(NodeTB *n, BSTB *dict); 
};

#endif
