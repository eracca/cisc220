/*Game.cc
*/

#include "Game.hh"
#include "BSTB.hh"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

Game::Game(string infile){
    //liz
    readTreeFromFile(infile);  
}
void Game::startGame(){
    wordlist = new BSTB();
    srand(time(NULL));
    int input; 
    cout << "How many letters would you like?" << endl;
    cin >> input;
    numletters = input; 
    cout << "got some" << endl; 
    cout << numletters << endl; 
    currletters = getLetters(numletters);  
    cout << "Your letters are: ";
    for (int i= 0; i < numletters; i++){
        cout << currletters[i] << " " ; 
    }
    cout << endl; 
    getWords();
    checkWordsForScore();  
}

void Game::readTreeFromFile(string dictfile){
    dict = new BSTB();
    ifstream file(dictfile.c_str());
    string word; 
    while (!file.eof()){
        file >> word; 
        if (!file.eof()){
            dict->insert(word);
        }
    }
    return; 
}
char* Game::getLetters(int x){  
    cout << "trying to get letters" << endl; 
    char vowels[5] = {'a','e','i','o','u'}; 
    char cons[21] = {'b','c','d','f','g','h','j','k','l','m','n','p',
                           'q','r','s','t','v','w','x','y','z'}; 
    cout << "its not the constants" << endl;
    char *letters = new char[numletters];
    cout << "initialize" << endl;   
    cout << numletters << endl; 
    int numVowels = rand() % x+ 1; 
    cout <<  "wht" <<  endl;
    int numCons = numletters - numVowels; 
    cout << "entering first loop" << endl; 
    for (int i = 0 ; i < numVowels; i++){
        letters[i] = vowels[rand() % numVowels]; 
        cout << "i: " << i << " , " << currletters[i] << endl; 
    }
    cout << "entering second loop" << endl; 
    for (int j = numVowels ; j< numletters; j++){
        letters[j] = cons[rand() % numCons]; 
    }
    cout << "gucci" << endl ;
    return letters;  
}
void Game::getWords(){
    //liz
    string word; 
    while (true){
        cout << "Enter a word or -1 if you are finished. " << endl
        << "word: "; 
        getline (cin, word);
        if (word == "-1"){
            return; 
        }
        if (checkWLetters(word)){
            wordlist->insert(word); 
        }
    }
    return;  
}
bool Game::checkWLetters(string s){
    //liz
    //not working
    for (int c = 0; c < s.size(); c++){
        bool charMatch = false;
        for (int i = 0; i < numletters; i++){
            if (s[c] == currletters[i]){
                charMatch == true; 
            }
        }
        if (!charMatch){
            return false; 
        }
    }
    return true;             
}

void Game::checkWordsForScore(){
    cout << wordlist->getScore(dict) << endl; 
    return; 
}

