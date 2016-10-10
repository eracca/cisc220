/*LLPQ.hh
*/

#ifndef LLPQ_HH_
#define LLPQ_HH_

class LLPQ {
	LLNode* first;
	int size;
public:
	LLPQ();
	~LLPQ();
	void printLLPQ();
	void addFirst(char x, int co = -1);
	LLNode* remFirst();
	int findCode(char k);
	void sortLL();
	void insertUnique(char c);
	void insertOrder(LLNode *n);
};


#endif
