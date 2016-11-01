/*LLHuff.hh
*/

#ifndef LLHUFF_HH_
#define LLHUFF_HH_

<<<<<<< HEAD
class LLHuff {
	string file;
	LLNode *root;
	int size;
public:
	LLPQ *pq;
	LLPQ *ascii;
	LLHuff(string f)
		~LLHuff();
	void MakeHuff();
	void FindCode(LLNode *root, string path);
	void ReadFile();
	void compressFile();
};

#endif
=======
#include "LLNode.hh"
#include "LLPQ.hh"

class LLHuff {
    string file;
    LLNode *root; 
    int size;  
public:
    LLPQ *pq;
    LLPQ *ascii;
    LLHuff(string f);
    ~LLHuff(); 
    void MakeHuff();
    void FindCode(); 
    void HelpFindCode(LLNode *root, string path);
    void ReadFile();
    void ReadAscii(); 
    void compressFile(); 
};

#endif
>>>>>>> 728ed1c5585fae33fa180d0a4bd7d08d1e7084cd
