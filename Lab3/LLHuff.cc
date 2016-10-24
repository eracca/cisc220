/*LLHuff.cc
*/

#include "LLHuff.hh"
#include "LLPQ.hh"
#include "LLNode.hh"

LLHuff::LLHuff(string f){
    file = f; 
    pq = new LLPQ(); 
}

LLHuff::~LLHuff(){
    //
}

LLHuff::MakeHuff(){
    while (pq.size > 0){
        LLNode *leftChild = pq.remFirst(); 
        LLNode *rightChild = pq.remFirst();
        LLNode *parent = new LLNode("*"); 
        parent->count = leftChild->count + rightChild->count; 
        parent->left = leftChild; 
        parent->right = rightChild;
        pq.insertInOrder(parent); 
    }
    root = pq->first;  
}

LLHuff::FindCode(){
    delete pq; 
    pq = new LLPQ(); 
    HelpFindCode(root, "");   
}

LLHuff::HelpFindCode(LLNode *root, string path){
    //check with TA or Dr. Y 
    if (root== NULL){
        return; 
    }
    HelpFindCode(root->left, path+"0");
    root->code = path; 
    if (root->data != "*"){
        pq.insertInOrder(root); 
    }
    HelpFindcode(root->right, path+ "1"); 
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
