/*LLHuff.cc
*/

#include "LLHuff.hh"
#include "LLPQ.hh"
#include "LLNode.hh"
#include <iostream>
#include <fstream>

using namespace std;

LLHuff::LLHuff(string f){
    file = f; 
    root = NULL; 
    size = 0; 
    pq = new LLPQ(); 
    ascii = new LLPQ(); 
}

LLHuff::~LLHuff(){
    //NEEDS WORK
}

void LLHuff::MakeHuff(){
    while (pq->size > 1){
        LLNode *leftChild = pq->remFirst(); 
        leftChild->next = NULL; 
        LLNode *rightChild = pq->remFirst();
        leftChild->next = NULL; 
        LLNode *parent = new LLNode('*'); 
        parent->count = leftChild->count + rightChild->count; 
        parent->left = leftChild; 
        parent->right = rightChild;
        pq->insertInOrder(parent); 
    }
    root = pq->first;  
}

void LLHuff::FindCode(){ 
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
    cout << "I am trying to compress the file" << endl; 
    ReadFile();//read file first time to make pq
    cout << "I read the file" << endl; 
    FindCode();//find all the codes
    cout << "I found the codes" << endl;
    pq->printLLPQ(); 
    ofstream outfile("compressed.txt",ios::out); //open file for writing
    cout << "I opened the file for writing" << endl; 
    fstream infile(file.c_str(),ios::in); //open file for reading
    cout << "I opnened the file for reading" << endl; 
    char k; 
    string comp;  
    while (infile.get(k)){
        comp = pq->findCode(k);
        cout << k << endl; 
        cout << "I found the code" << endl; 
        outfile << comp<< " "; 
    }
    infile.close(); 
    outfile.close();  

