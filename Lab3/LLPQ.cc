/*LLPQ.cc
*/

#include "LLPQ.hh"
#include "LLNode.hh"
#include <stdlib.h>

LLPQ::LLPQ(){
}

LLPQ::~LLPQ(){
}

void LLPQ::printLLPQ(){
}

void LLPQ::addFirst(char x,  int c0=-1){
	struct LLNode* temp = (struct LLNode*) malloc(sizeof(struct LLNode));
	temp->data = x;
	temp->next = first;
	first = temp;
}

LLNode* LLPQ::remFirst(){
	struct LLNode *temp;
	temp = first;
	first = first->next;

	free(temp);
}

int LLPQ::findCode(char k){
}

void LLPQ::sortLL(){
	struct LLNode *temp;
	for (first; size; temp->next) {
		if((temp->next)==(temp->prev)){
		}
	}

}

void LLPQ::insertUnique(char c){
}

void LLPQ::insertOrder(LLNode *n){
	
	if (first == NULL){
		first = new LLNode(*n);
		return; 
	}
 
}

