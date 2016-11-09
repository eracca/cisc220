/*BSTB.hh
*/

#ifndef PARTBBSTB_HH_
#define PARTBBSTB_HH_

#include "NodeTB.hh"
#include <stdlib.h>
#include <string>

using namespace std;

class PartBBSTB {
	NodeTB *root;
	int count;
public:
	PartBBSTB();
	~PartBBSTB();
	void delTree(NodeTB *n);
	bool insert(string x);
	bool search(string x);
	bool search(NodeTB *n, string x);
	void adjustBalances(NodeTB *n);
	int height(NodeTB *n);
	int balance(NodeTB n);
	NodeTB *rotateRight(NodeTB *n);
	NodeTB *rotateLeft(NodeTB *n);
};

#endif