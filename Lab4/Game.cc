/*Game.cc
*/

#include "Game.hh"
#include "BSTB.hh"
#include <string>
#include <fstream>

using namespace std;

Game::Game(){
    //liz
}
Game::Game(string infile){
    //liz
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
    //liz
}
void Game::getWords(){
}
bool Game::checkWLetters(string s){
    //liz
}
void Game::checkWordsForScore{
}
