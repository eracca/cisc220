/*Game.cc
*/

#include "Game.hh"
#include "BSTB.hh"
#include <string>
#include <fstream>

using namespace std;

Game::Game(string infile){
    //liz
    readTreeFromFile(infile);  
}
void Game::startGame(){

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

    
}
void Game::getWords(){
    //liz
    string word; 
    while (word != "-1"){
        cout << "Enter a word or -1 if you are finished. " << endl
        << "word: "; 
        getline (cin, word); 
        if (word != "-1"){
            wordlist->insert(word); 
        }
    }
    return;  
}
bool Game::checkWLetters(string s){
    //liz
    for (char & c : s){
        bool charMatch = false;
        for (int i = 0; i < numletters; i++){
            if (c == currletters[i]){
                charMatch == true; 
            }
        }
        if (!charMatch){
            return false; 
        }
    }
    return true;             
}
void Game::checkWordsForScore{
}
