/*BSTB.hh
*/

#ifndef BSTB_HH_
#define BSTB_HH_

#include "NodeTB.hh"
#include <stdlib.h>
#include <string>

using namespace std;

class BSTB {
	NodeTB *root;
	int count;
public:
	BSTB();
	~BSTB();
	void delTree(NodeTB *n);
	bool insert(string x);
	void printTreeio();
	void printTreeio(NodeTB *n);
	void printTreePre();
	void printTreePre(NodeTB *n);
	void printTreePost();
	void printTreePost(NodeTB *n);
	bool search(string x);
	bool search(NodeTB *n, string x);
	void adjustBalances(NodeTB *n);
	int height(NodeTB *n);
	int balance(NodeTB *n);
	NodeTB *rotateRight(NodeTB *n);
	NodeTB *rotateLeft(NodeTB *n);
	int getScore(BSTB *dict);
	int getScore(NodeTB *n, BSTB *dict);
};

#endif