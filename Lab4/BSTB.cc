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
		root = new NodeTB(x);
		count++;
		return true;
	}
	NodeTB* tmp = root;
	while (tmp != NULL) {
		if (x == tmp->word) {
			cout << x << " is already in the tree" << endl;
			return false;
		}
		if (x < tmp->word) {
			if (tmp->left == NULL) {
				tmp->left = new NodeTB(x);
				count++;
				return true;
			}
			tmp = tmp->left;
		}
		if (x > tmp->word) {
			if (tmp->right == NULL) {
				tmp->right = new NodeTB(x);
				count++;
				return true;
			}
			tmp = tmp->right;
		}
	}
}

void BSTB::printTreeio(){
	cout << "In order printout: " << endl;
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
	cout << "Pre order printout: " << endl;
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
	else {
		cout << n->word << endl;
		printTreePre(n->left);
		printTreePre(n->right);
	}
	
}

void BSTB::printTreePost() {
	cout << "Post order printout: " << endl;
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
			return search(n->left, x);
		}
		if (n->word < x) {
			return search(n->right, x);
		}
	}
	return false;
}

void BSTB::adjustBalances() {
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	else {
		adjustBalances(root);
	}
}


void BSTB::adjustBalances(NodeTB *n){
	if (height(n) > 1) {
		if (height(n->left) > 0) {
			rotateLeft(n);
		}
		else {
			rotateRight(n->left);
			rotateLeft(n);
		}
	}
	else if (height(n) < -1) {
		if (height(n->right) > 0) {
			rotateLeft(n->right);
			rotateRight(n);
		}
		else {
			rotateRight(n);
		}
	}
			
}

int BSTB::height() {
	cout << "Printing out height" << endl;
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return 0;
	}
	else {
		height(root);
	}
}

int BSTB::height(NodeTB *n) {
	//helper function for adjust balances
	int h = 0;
	if (n != NULL) {
		int hleft = height(n->left);
		int hright = height(n->right);
		h = 1 + max(hleft, hright);
	}
	return h;
}


NodeTB* BSTB::rotateRight(NodeTB *root) {
	//liz
	NodeTB *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	return tmp;
}
	NodeTB* BSTB::rotateLeft(NodeTB *n) {
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