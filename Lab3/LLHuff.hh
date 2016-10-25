/*LLHuff.hh
*/

#ifndef LLHUFF_HH_
#define LLHUFF_HH_

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