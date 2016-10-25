/*LLPQ.hh
*/

#ifndef LLPQ_HH_
#define LLPQ_HH_

class LLPQ {
    LLNode* first;
    LLNode* last; 
    int size;
public:
    LLPQ();
    ~LLPQ();
    void printLLPQ();
    void addFirst(char x, string co="");
    void addAtFirst(char x, string co="");
    LLNode* remFirst();
    string findCode(char k);
    void sortLL();
    void insertUnique(char c);
    void insertInOrder(LLNode *n)
};


#endif
