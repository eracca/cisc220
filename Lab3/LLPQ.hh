/*LLPQ.hh
*/

#ifndef LLPQ_HH_
#define LLPQ_HH_

#include "LLNode.hh"
#include <string>

class LLPQ {
    friend class LLHuff; 
public:
    LLNode* first;
    LLNode* last; 
    int size;
    LLPQ();
    ~LLPQ();
    void printLLPQ();
    void addFirst(char x, string co="");
    void addAtFirst(char x, string co="");
    LLNode* remFirst();
    string findCode(char k);
    void sortLL(); 
    void insertUnique(char c);
    void insertInOrder(LLNode *n);
};


#endif
