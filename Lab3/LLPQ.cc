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
    if (size ==0){
        addFirst(x, co); 
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
    LLNode *tmp = first; 
    while (tmp->next != NULL){
        if (tmp->data == k){
            return tmp->code; 
        tmp=tmp->next; 
        }
    }
    return NULL; //char not found
}

void LLQ::sortLL(){
    LLNode *tmp = first; 
    LLNode *lowPrev = NULL: 
    LLNode *lowest = first; 
    LLNode *sort = NULL; 
    int min = first->count; 
    while (sort->next != NULL){
        while (tmp ->next != NULL){
            if (tmp->next->count < min){
                min = tmp->next->count; 
                lowest = tmp->next; 
                lowPrev = tmp; 
            }
            tmp =  tmp->next; 
        }
        if (sort == NULL && lowest != first){ //first pass, first node is wrong
            lowPrev->next = lowest->next; 
            lowest->next = first; 
            first = lowest;
            sort = first; 
        }
        else if (sort != NULL){ //all other passes
            lowPrev->next =  lowest->next;
            lowest->next = sort->next;
            sort->next = lowest; 
            sort = sort->next;
            tmp = sort;   
        }
    }
    last =  sort; 
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
    if (size ==0){
        first = n; 
        last = n; 
        size++; 
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
        while (tmp->next != NULL){
            if (n->count > tmp->count){
                n->next = tmp->next; 
                tmp->next n; 
                size ++; 
                return; 
            }
        }
    }
}

