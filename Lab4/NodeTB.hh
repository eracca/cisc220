/*NodeTB.hh
*/
//Allan Chandy & Liz Racca

#ifndef NODETB_HH_
#define NODETB_HH_

#include <string> 

using namespace std;

class NodeTB {
<<<<<<< HEAD
	friend class BSTB;
	NodeTB *left;
	NodeTB *right;
	NodeTB *parent;
	string word;
public:
	NodeTB(string w);
	~NodeTB();
=======
    friend class BSTB; 
    NodeTB *left;
    NodeTB *right; 
    NodeTB *parent; 
    string word; 
public:
    NodeTB(string w); 
    ~NodeTB(); 
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
};

#endif