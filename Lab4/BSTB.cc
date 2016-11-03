/*BSTB.cc
*/

#include "BSTB.hh"
#include "NodeTB.hh"
#include <stdlib.h>
#include <iostream> 
#include <string>

using namespace std; 

BSTB::BSTB(){
    //liz
    root = NULL;
    count = 0; 
}
BSTB::~BSTB(){
    //liz 
    if(root == NULL){
        cout << "The tree is empty" << endl; 
        return;
    }
    else{
        delTree(root); 
    }
}
void BSTB::delTree(NodeTB *cur){
    if(cur == NULL){
        return;
    }
    delTree(cur->left);
    delTree(cur->right); 
    delete cur; 
}
bool BSTB::insert(string x){
}
bool BSTB::insert(string x, NodeTB *n){
}
void BSTB::printTreeio(){
}
void BSTB::printTreeio(NodeTB *n){
}
void BSTB::printTreePre(){
}
void BSTB::printTreePre(NodeTB *n){
}
void BSTB::printTreePost(){
    //liz
    if (root == NULL){
        cout << "The tree is empty" << endl; 
        return;
    }
    else{
        printTreePost(root);
    }
}
void BSTB::printTreePost(NodeTB *n){
    //liz
    if(n != NULL){
        printTreePost(n->left);
        printTreePost(n->right);
        cout << n->word << endl; 
    }
}
bool BSTB::search(string x){
    //liz
    if (root == NULL){
        cout << "The tree is empty" << endl; 
        return 0;  
    }
    else{
        search(root, x);
    }
}
bool BSTB::search(NodeTB *n, string x){
    //liz
    if (n != NULL){
       if (n->word == x){
           return true; 
       }
       if (n->word > x){
           search(n->left, x); 
       }
       if (n->word < x){
           search(n->right, x); 
       }
    }
    return false; 
}
void BSTB::adjustBalances(NodeTB *n){
}
int BSTB::height(NodeTB *n){
    //helper function for adjust balances
    int h = 0; 
    if (n!=NULL){
        int hleft = height(n->left); 
        int hright = height(n->right); 
        h = max(hleft, hright)+1; 
    }
    return h; 
}
NodeTB* BSTB::rotateRight(NodeTB *root){
    //liz
    NodeTB *tmp = root->left; 
    root->left = tmp->right; 
    tmp->right = root; 
    return tmp; 
}
NodeTB* BSTB::rotateLeft(NodeTB *root){
    //liz
    NodeTB *tmp = root->right; 
    root->right = tmp->left; 
    tmp->left = root;  
    return tmp; //return pointer to new root  
}
int BSTB::getScore(BSTB *dict){
    return getScore(root, dict); 
}
int BSTB::getScore(NodeTB *n, BSTB *dict){
    int score;
    if (n!=NULL){
        if (dict->search(n->word)){
            score = 3;
        }
        else{
            score = -6; 
        }
        return score + getScore(n->left, dict) + getScore(n->right, dict); 
    }
    return 0; 
}
