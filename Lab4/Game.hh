/*Game.hh
*/

#ifndef GAME_HH__
#define GAME_HH_

#include "BSTB.hh"
#include <string>

using namespace std; 

class Game {
    BSTB *dict; 
    int numletters; 
    char *currletters; 
    int totalwords; 
    BSTB *wordlist; 
    int numright; 
public:
    Game(string infile); 
    void startGame(); 
    void readTreeFromFile(string dictfile); 
    char* getLetters(int x); 
    void getWords(); 
    bool checkWLetters(string s); 
    void checkWordsForScore(); 
};

#endif
