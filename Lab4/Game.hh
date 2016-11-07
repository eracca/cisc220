/*Game.hh
*/

#ifndef BSTB_HH_
#define BSTB_HH_

#include "BSTB.hh"
#include <string>

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
