/*BSTB.cc
*/

#include "BSTB.hh"
#include "NodeTB.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#define NOMINMAX

using namespace std; 

BSTB::BSTB(){
    //liz
    root = NULL;
	count = 0;
}
BSTB::~BSTB(){
    //liz 
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	else {
		delTree(root);
	}
}

void BSTB::delTree(NodeTB *cur) {
	if (cur == NULL) {
		return;
	}
	delTree(cur->left);
	delTree(cur->right);
	delete cur;
}

bool BSTB::insert(string x){
	if (root == NULL) {
		return;
	}
	else {
		insert(x);
	}
}
bool BSTB::insert(string x, NodeTB *n) {
	if (n == NULL) {
		n = new NodeTB(x);
	}
	else if (x < n->word) {
		insert(x, n->left);
		if (height(n->left) - height(n->right) == 2) {
			if (x < n->left->word) {
				rotateLeft(n);
			}
			else {
				rotateRight(n->left);
				rotateLeft(n);
			}
		}
	}
	else if (x > n->word) {
		insert(x, n->right);
		if (height(n->right) - height(n->left) == 2) {
			if (x < n->right->word) {
				rotateRight(n);
			}
			else {
				rotateLeft(n->right);
				rotateLeft(n);
			}
		}
	}
}
void BSTB::printTreeio(){
	//liz
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	else {
		printTreeio(root);
	}
}
void BSTB::printTreeio(NodeTB *n){
	if (n == NULL) {
		return;
	}

	printTreePre(n->left);
	cout << n->word << endl;
	printTreePre(n->right);

}
void BSTB::printTreePre(){
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	else {
		printTreePre(root);
	}
}
void BSTB::printTreePre(NodeTB *n){
	if (n == NULL) {
		return;
	}
		
	cout << n->word << endl;
	printTreePre(n->left);
	printTreePre(n->right);
}

void BSTB::printTreePost() {
	//liz
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	else {
		printTreePost(root);
	}
}

void BSTB::printTreePost(NodeTB *n) {
	//liz
	if (n != NULL) {
		printTreePost(n->left);
		printTreePost(n->right);
		cout << n->word << endl;
	}
}

bool BSTB::search(string x){
	//liz
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return 0;
	}
	else {
		search(root, x);
	}
}
bool BSTB::search(NodeTB *n, string x){
    //liz
	if (n != NULL) {
		if (n->word == x) {
			return true;
		}
		if (n->word > x) {
			search(n->left, x);
		}
		if (n->word < x) {
			search(n->right, x);
		}
	}
	return false;
}


bool BSTB::isBalanced(NodeTB  *n){

}

void BSTB::adjustBalances(NodeTB *n){
	
}

int BSTB::height(NodeTB *n) {
	//helper function for adjust balances
	int h = 0;
	if (n != NULL) {
		int hleft = height(n->left);
		int hright = height(n->right);
		h = max(hleft, hright) + 1;
	}
	return h;
}

NodeTB* BSTB::rotateRight(NodeTB *n){
    //liz
	NodeTB *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	return tmp;
}
NodeTB* BSTB::rotateLeft(NodeTB *n){
    //liz
	NodeTB *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	return tmp; //return pointer to new root  
}
int BSTB::getScore(BSTB *dict) {
	return getScore(root, dict);
}
int BSTB::getScore(NodeTB *n, BSTB *dict) {
	int score;
	if (n != NULL) {
		if (dict->search(n->word)) {
			score = 3;
		}
		else {
			score = -6;
		}
		return score + getScore(n->left, dict) + getScore(n->right, dict);
	}
	return 0;
}