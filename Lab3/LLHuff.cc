/*LLHuff.cc
*/

#include "LLHuff.hh"
#include "LLPQ.hh"
#include "LLNode.hh"
#include <iostream>
#include <fstream>

LLHuff::LLHuff(string f){
    //NEEDS WORK
    file = f; 
    pq = new LLPQ(); 
    ascii = new LLPQ(); 
}

LLHuff::~LLHuff(){
    //NEEDS WORK
}

void LLHuff::MakeHuff(){
    while (pq->size > 0){
        LLNode *leftChild = pq->remFirst(); 
        LLNode *rightChild = pq->remFirst();
        LLNode *parent = new LLNode('*'); 
        parent->count = leftChild->count + rightChild->count; 
        parent->left = leftChild; 
        parent->right = rightChild;
        pq->insertInOrder(parent); 
    }
    root = pq->first;  
}

void LLHuff::FindCode(){
    delete pq; 
    pq = new LLPQ(); 
    HelpFindCode(root, "");   
}

void LLHuff::HelpFindCode(LLNode *root, string path){
    //check with TA or Dr. Y 
    if (root== NULL){
        return; 
    }
    HelpFindCode(root->left, path+ "0");
    root->code = path; 
    if (root->data != '*'){
        pq->insertInOrder(root); 
    }
    HelpFindCode(root->right, path+ "1"); 
}

void LLHuff::ReadFile(){
   ifstream infile(file.c_str(),ios::in); // open file
   char k;
   while (infile.get(k)) { // loop getting single characters
       pq->insertUnique(k);// inserting the character k into the priority queue
   }
   infile.close();
}

void LLHuff::ReadAscii(){
    cout << file << endl; 
    ifstream infile("asciitable.txt",ios::in);
    char ch;
    string asciicode;
    if (!infile.is_open()){
        return;
    }
    infile >> asciicode;
    ascii->addFirst(' ',asciicode);
    infile >> asciicode; 
    while (infile>>ch){
        cout << ch;
        infile>>asciicode;
        cout << asciicode << endl;
        ascii->addAtFirst(ch,asciicode); 
    }
    cout << endl;
    infile.close(); 
    //////////////////////////////////
    ifstream infile2(file.c_str(),ios::in); 
    ofstream outfile("asciivsn.txt",ios::out); 
    char k; 
    string comp;
    while (infile2.get(k)) {
        cout << k; 
        comp = ascii->findCode(k); 
        if (comp == ""){
            cout << "ERROR WITH " << k << endl; 
        }
        else {
            cout << k << ":" << comp << endl; 
            outfile << comp << " "; 
        }
    }
    cout << endl; 
    infile2.close(); 
    outfile.close(); 
}

void LLHuff::compressFile(){
    ReadFile();//read file first time to make pq
    MakeHuff();//make Huffman tree
    FindCode();//find all the codes
    ofstream outfile("compressed.txt",ios::out); //open file for writing
    fstream infile(file.c_str(),ios::in); //open file for reading
    char k; 
    string comp; 
    while (infile.get(k)){
        comp = pq->findCode(k); 
        outfile << comp<< " "; 
    }
    infile.close(); 
    outfile.close();  
}
