/*LLPQ.cc
*/

#include "LLPQ.hh"
#include "LLNode.hh"
#include <iostream>
#include <string>

using namespace std; 

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
    last = NULL; 
}

void LLPQ::printLLPQ(){
    LLNode *n = first;
    while (n != NULL){
        cout << n->data << ":"<< n->count << ":" << n->code << "->";
        n=n->next;
    }
    cout << endl; 
}

void LLPQ::addFirst(char x, string co){
    LLNode *n = new LLNode(x, co);
    first =  n; 
    last =  n; 
    size++; 
}

void LLPQ::addAtFirst(char x, string co){
    if (size ==0){
        addFirst(x); 
    }
    else{
        LLNode *n = new LLNode(x, co);
        n->next = first;  
        first = n; 
        size++;
    }
}

LLNode* LLPQ::remFirst(){
    LLNode *tmp = first; 
    first = first->next; 
    size--; 
    return tmp; 
}

string LLPQ::findCode(char k){
    cout << "trying to find code" << endl; 
    LLNode *tmp = first; 
    while (tmp->next != NULL){
        if (tmp->data == k){
            cout << "this this is the problem"<<  endl; 
            return tmp->code;  
        }
        tmp=tmp->next; 
    }
    cout << "character not found" << endl; 
    return NULL; //char not found
}

void LLPQ::sortLL(){
    LLPQ *sorted =  new LLPQ(); 
    LLNode *tmp = first; 
    LLNode *tmpNext = tmp-> next; 
    while (tmp!=NULL){
        tmpNext=tmp->next;
        sorted->insertInOrder(tmp); 
        tmp=tmpNext;  
    }
    first = sorted->first;
    last = sorted->last;   
}
    

void LLPQ::insertUnique(char c){
    if (size==0){
        addFirst(c);
        return; 
    }
    LLNode *tmp= first; 
    while (tmp !=NULL){
        if (tmp->data ==c){
            tmp->count++; 
            return; 
        }
        tmp=tmp->next; 
    }
    addAtFirst(c); 
}

void LLPQ::insertInOrder(LLNode *n){
    if (size ==0){ //n is first to be added
        first = n; 
        last = n;
        n->next = NULL;  
        size++;
    }
    else if (n->count <= first->count){ //n goes before first
        n->next = first; 
        first = n; 
        size++; 
    }
    else if (n->count >= last-> count){ //n goes after last
        last->next = n;  
        n->next = NULL; 
        last = n; 
        size++;
    }
    else{ //n goes somewhere else
        LLNode *tmp = first; 
        while (tmp->next->count < n->count){
            tmp=tmp->next; 
        }
        n->next=tmp->next; 
        tmp->next = n; 
        size++;
    }
}

