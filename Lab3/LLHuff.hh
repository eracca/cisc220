/*LLHuff.hh
*/

#ifndef LLHUFF_HH_
#define LLHUFF_HH_

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
