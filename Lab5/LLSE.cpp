/*
 * LLSE.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Debra
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

LLSE::LLSE() {
	first = NULL;
	last = NULL;
	size = 0;
}
LLSE::~LLSE() {
	Node *tmp = first;
	for(int i = 0; i < size; i++) {
		tmp = first->next;
		delete first;
		first = tmp;
	}
}

void LLSE::printLL() {
	Node *tmp = first;
	while (tmp != NULL) {
		cout << tmp->count <<":"<<tmp->word << endl;
		tmp = tmp->next;
	}
}

void LLSE::addFirst(string w) {
	first = new Node(w);
	last = first;
	size = 1;
}

void LLSE::insertUnique(string w) {
	Node *tmp = first;
	if (tmp == NULL) {
		addFirst(w);
	}
	else {
		while (tmp != NULL && tmp->word < w)  {
			tmp = tmp->next;
		}
		if ((tmp!= NULL) && (tmp->word == w)) {
			tmp->count++;
		}
		else {
			Node *tmp2 = new Node(w);
			if (tmp != NULL) {
				if (tmp->prev != NULL) {
					tmp->prev->next = tmp2;
					tmp2->prev = tmp->prev;
				}
				else {
					first = tmp2;
				}
				tmp2->next = tmp;
				tmp->prev = tmp2;
			}
			else {
				last->next = tmp2;
				tmp2->prev = last;
				last = tmp2;
			}
			size++;

		}
	}
}

// Write an insertion Sort on the linked list (not an array, 
// a linked list!
void LLSE::insertionSortLL() {
    Node* tmp=first;  
    Node* tmp2; 
    Node* key = first; 
    while (tmp->next != NULL){
        //take key out. tmp holds place of last sorted node
        key = tmp->next; 
        tmp->next = key->next; //need to handle last 
        //insert key in order
        //put key at front if it belongs there
        if (key->count < first->count){
            key->next =  first; 
            first = key; 
        }
        else{
            tmp2 = first; 
            while (key->count > tmp2->next->count && tmp2 != tmp){
                tmp2 = tmp2->next; 
            }
            if (tmp2 == tmp){ //add key to end of sorted section
                key->next = tmp->next; 
                tmp->next = key;  
                tmp = key; 
            }
            else{ //add key in between tmp2 and tmp2->next
                key->next = tmp2->next; 
                tmp2->next = key; 
            }
        }
    }
    last = tmp; 
}

// Convert the linked list to an array of nodes and return that array
Node *LLSE::convertToArray() {
    Node* arr = new Node[size]; 
    Node* tmp = first;  
    for (int j = 0; j< size ; j++){
        arr[j] = *tmp; 
        tmp = tmp->next; 
    }
    return arr;  
}

// For the quicksort - the partition
int LLSE::partition(int beg,int end) {
    int p = beg;
    Node pivot= wordarr[p]; 
    Node tmp;
    for (int i = beg+1;i <= end; i++){
        if (wordarr[i].count <= pivot.count){
            p++;
            tmp = wordarr[i];
            wordarr[i] = wordarr[p];
            wordarr[p] = tmp;
        }
    }
    tmp= wordarr[p];
    wordarr[p]= wordarr[beg];
    wordarr[beg] =tmp;
    return p;
}

// your recursive quicksort
void LLSE::quickSort( int beg, int end) {
    if (beg < end){
        int j = partition(beg,end);
        quickSort(beg, j-1); 
        quickSort(j+1, end); 
    }
}

void LLSE::swap(Node &a, Node &b){
    Node tmp = a;
    a = b; 
    b = tmp;
    return;
}

void LLSE::heapify(int heapMax){
   int i = (heapMax-1)/2; //position of last parent; 
   while (i >= 0){
       int left = 2*i+1;
       int right = 2*i+2; 
       if (wordarr[left].count > wordarr[i].count){
           swap(wordarr[left], wordarr[i]); 
       }
       if (right <= heapMax && wordarr[right].count > wordarr[i].count){
           swap(wordarr[right], wordarr[i]); 
       }
       i--;
   }
}
//Sort the heap array using heapsort
void LLSE::heapSort() { 
    int heapMax = size-1 ;
    wordarr = convertToArray(); 
    for (int i = 0; i< size; i++){
        heapify(heapMax); 
        swap(wordarr[0], wordarr[heapMax]); 
        heapMax--; 
    }
    return; 
}
