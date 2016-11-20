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
    cout << "adding " << x << endl; 
    if (root == NULL){
        root = new NodeTB(x); 
        count ++; 
        return true; 
    } 
    NodeTB* tmp = root; 
    while (tmp != NULL){
        if (x == tmp->word){
            cout << x << " is already in the tree" << endl; 
            return false; 
        }
        if (x < tmp->word){
            if (tmp->left == NULL){
                tmp->left = new NodeTB(x); 
                tmp->left->parent == tmp; 
                count ++; 
                //adjustBalances(tmp->left); 
                return true; 
            }
            tmp=tmp->left; 
        }
        if (x > tmp->word){
            if (tmp->right == NULL){
                tmp->right = new NodeTB(x); 
                tmp->right->parent =  tmp;
                count ++;
                //adjustBalances(tmp->right); 
                return true; 
            }
            tmp= tmp->right;
        }
    }
}
void BSTB::printTreeio(){ 
    cout << "In order printout: " << endl; 
    if (root ==NULL){
        cout << "The  tree  is empty" << endl;
        return;
    }
    else{
        printTreeio(root); 
        cout << endl; 
    }
}
void BSTB::printTreeio(NodeTB *n){
    if (n != NULL){
        printTreeio(n->left);
        cout << n->word << " "; 
        printTreeio(n->right); 
    }
}
void BSTB::printTreePre(){
    cout << "Pre order printout: " << endl; 
    if (root == NULL){
        cout << "The tree is empty" << endl; 
        return;  
    }
    else{
        printTreePre(root);
        cout << endl;  
    }
}
void BSTB::printTreePre(NodeTB *n){
    if (n!= NULL){
        cout << n->word << " "; 
        printTreePre(n->left);
        printTreePre(n->right);  
    }
}
void BSTB::printTreePost(){
    //liz
    cout << "Post order printout: " << endl; 
    if (root == NULL){
        cout << "The tree is empty" << endl; 
        return;
    }
    else{
        printTreePost(root);
        cout << endl; 
    }
}
void BSTB::printTreePost(NodeTB *n){
    //liz
    if(n != NULL){
        printTreePost(n->left);
        printTreePost(n->right);
        cout << n->word << " "; 
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
           return search(n->left, x); 
       }
       if (n->word < x){
           return search(n->right, x); 
       }
    }
    return false; 
}
void BSTB::adjustBalances(NodeTB *n){
    //n begins as the node  that  was inserted
    NodeTB *z = n; 
    NodeTB *y;
    NodeTB *x; 
    int bF = balance(z); 
    //find z
    while (bF <2 && bF >-2){
        z = z->parent;
        if (z == NULL){
            return;  //reached the root, still in balance
        }
        bF = balance(z);
    }
    cout << "unbalanced at: " << z->word << " , balance: " << bF << endl; 
    //find y
    if (n->word < z->word){
        y = z->left; 
        //find x
        if (n->word < y->word){
            //case 1
            cout << "case 1" << endl; 
            x = y->left; 
            rotateRight(z);
        }
        else{
            //case 2
            cout << "case 2" << endl;
            x = y->right; 
            rotateLeft(y);
            rotateRight(z); 
        }
    }
    else{
        y = z->right; 
        //find x
        if  (n->word > y->word){
            cout << "case 3" << endl; 
            x =  y->right; 
            //case 3
            rotateLeft(z); 
        }
        else{
            cout << "case 4" << endl; 
            x = y->left; 
            //case 4
            rotateRight(y); 
            rotateLeft(z); 
        }
    }
}
 
int BSTB::height(NodeTB *n){
    //helper function for adjust balances
    int l;
    int r; 
    if (n == NULL){
        return 0; 
    }
    l = height(n->left);
    r= height(n->right); 
    if (l > r){
        return l+1; 
    }
    else{
        return r+1; 
    }
}
int BSTB::balance(NodeTB *n){
    int bF = height(n->right)-height(n->left); 
    cout << "word: " << n->word << " balance: " << bF <<endl;
    return bF;
}
NodeTB* BSTB::rotateRight(NodeTB *n){
    cout << "I rotated: " << n->word << " right." << endl; 
    //liz
    NodeTB *tmp = n->left; 
    tmp->parent = n->parent; 
    if (n->word ==root->word){
        root = tmp; 
        cout << "the root changed to " << tmp->word << endl; 
    }
    n->left = tmp->right;
    if (tmp->right != NULL){
        tmp->right->parent = n; 
    }
    tmp->right = n;
    n->parent = tmp; 
    return tmp; 
}
NodeTB* BSTB::rotateLeft(NodeTB *n){
    //issue in here concerning parent
    cout << "I rotated: " <<n->word << " left."<< endl;
    // liz 
    NodeTB *tmp = n->right; 
    tmp->parent = n->parent; 
    if (n->word==root->word){
        root = tmp; 
        cout << "the root changed to " << tmp->word << endl;
    } 
    n->right = tmp->left; 
    cout << "1 " ;
    if (tmp->left !=NULL){
        tmp->left->parent = n;
    }
    tmp->left = n;  
    n->parent = tmp;
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
