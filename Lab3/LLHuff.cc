/*LLHuff.cc
*/

#include "LLHuff.hh"
#include "LLPQ.hh"
#include "LLNode.hh"

LLHuff::LLHuff(string f){
    file = f; 
}

LLHuff::~LLHuff(){
    //
}

LLHuff::MakeHuff(){
    //NEEDS WORK
    LLNode *leftChild = pq.remFirst(); 
    LLNode *rightChild = pq.remFirst();
    LLNode *parent = new LLNode("*"); 
    parent->count = leftChild->count + rightChild->count; 
    parent->left = leftChild; 
    parent->right = rightChild;
    pq.insertInOrder(parent); 


    
}

LLHuff::FindCode(LLNode *root, int path){
}

LLHuff::ReadFile(){
   fstream infile(file.c_str(),ios::in); // open file
   char k;
   while (infile.get(k)) { // loop getting single characters
       pq->insertUnique(k);// inserting the character k into the priority queue
   }
   infile.close();
}

LLHuff::compressFile(){
}
