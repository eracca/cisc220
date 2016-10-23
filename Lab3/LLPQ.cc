/*LLPQ.cc
*/

#include "LLPQ.hh"
#include "LLNode.hh"

LLPQ::LLPQ(){
    first=NULL;
    last=NULL; 
    size=0; 
}

LLPQ::~LLPQ(){
    LLNode *tmp = first; 
    while (first != NULL){
        tmp = first->next; 
        delete first; 
        first = tmp; 
        size --;
    }
    first = NULL; 
    last = NULL: 
}

void LLPQ::printLLPQ(){
    LLNode *n = first;
    while (n != NULL){
        cout << n->data << "->";
        n=n->next;
    }
    cout << endl; 
}

void LLPQ::addFirst(char x,  string co= ""){
    LLNode *n = new LLNode(x, co);
    first =  n; 
    last =  n; 
    size++; 
}

void LLPQ::addAtFirst(char x, string co=""){
    LLNode *n = new LLNode(x, co);
    n->next = first;  
    first = n; 
    size++;
}

LLNode* LLPQ::remFirst(){
    LLNode *tmp = first; 
    first = first->next; 
    size--; 
    return tmp; 
}

string LLPQ::findCode(char k){
    LLNode *tmp = first; 
    while (tmp->next != NULL){
        if (tmp->data == k){
            return tmp->code; 
        tmp=tmp->next; 
        }
    }
    return NULL; //char not found
}

void LLPQ::sortLL(){
    //
}

void LLPQ::insertUnique(char c){
    LLNode *tmp= first; 
    while (tmp->next !=NULL){
        if (tmp->data ==c){
            tmp->count++; 
            return; 
        }
    }
    addatFirst(c, ""); 
}

void LLPQ::insertInOrder(LLNode *n){ 
    if (n->count <= first->count){  
        n->next = first; 
        first->prev= n; 
        size++; 
        first = n; 
        return; 
    }
    LLNode *tmp = first->next 
    while (tmp->next != NULL){
        if (n->count <= tmp->count){
            n->prev = tmp->prev; 
            n->prev->next = n; 
            n->next = tmp; 
            tmp->prev = n; 
            size++;
            return;  
        }
    tmp=tmp->next; 
    }
    tmp->next = n; 
    n->prev = n; 
    size ++; 
    last = n;  
}

