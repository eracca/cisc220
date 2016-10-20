/*LLPQ.cc
*/

#include "LLPQ.hh"
#include "LLNode.hh"

LLPQ::LLPQ(){
    first=NULL;
    size=0; 
}

LLPQ::~LLPQ(){
    if (size ==0){
        delete this; 
        return;  
    }
    if (size ==1){
        delete first; 
        delete this; 
        return; 
    }
    LLNode *tmp = first->next;
    while (tmp->next != NULL){
        delete tmp->prev; 
        tmp=tmp->next; 
    }
    delete tmp; 
    delete this; 
}

void LLPQ::printLLPQ(){
    LLNode *n = first;
    while (n != NULL){
        cout << n->data << "->";
        n=n->next;
    }
    cout << endl; 
}

void LLPQ::addFirst(char x,  int c0=-1){
    LLNode *n = new LLNode(x, c0);
    first =  n; 
    last =  n; 
    size++; 
}

void LLPQ::addAtFirst(char x, int c0=-1){
    LLNode *n = new LLNode(x, c0);
    n->next = first; 
    first->prev = n; 
    first = n; 
    size++;
}

LLNode* LLPQ::remFirst(){
    LLNode *tmp = first; 
    first = first->next; 
    delete first->prev; 
    first->prev = NULL;
    size--; 
    return tmp;   
}

int LLPQ::findCode(char k){
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
    //insertion sort bc I suckkkkkk
    LLNode *tmp; 
    LLNode *tmp2 = first;
    LLNode *n;  
    int minCount;
    //needs to be modified to reset first and last if these get messed with
    while (tmp2-> next !=NULL){
        tmp = tmp2;  
        minCount = tmp2->count;  
        while (tmp->next !=NULL){
            if (tmp->next->count < minCount) {
                minCount= tmp->next->count; 
                n=tmp->next; 
            }
            tmp= tmp->next; 
        }
        if (minCount != tmp2->count){
            n->prev->next = n->next; 
            n->next->prev = n->prev; 
            n->next = tmp2; 
            n->prev = tmp2->prev; 
            tmp2->prev = n;   
        }
        tmp2=tmp2->next; 
    }    
}

void LLPQ::insertUnique(char c){
    LLNode *tmp= first; 
    while (tmp->next !=NULL){
        if (tmp->data ==c){
            tmp->count++; 
            return; 
        }
    }
    addatFirst(c, -1); 
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

