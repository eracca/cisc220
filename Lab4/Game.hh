/*Game.hh
*/
<<<<<<< HEAD
//Allan Chandy & Liz Racca

#ifndef GAME_HH_
=======

#ifndef GAME_HH__
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
#define GAME_HH_

#include "BSTB.hh"
#include <string>

<<<<<<< HEAD
class Game {
	BSTB *dict;
	int numletters;
	char *currletters;
	int totalwords;
	BSTB *wordlist;
	int numright;
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile(string dictfile);
	char* getLetters(int x);
	void getWords();
	bool checkWLetters(string s);
	void checkWordsForScore();
};

#endif
=======
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
>>>>>>> ea460b931cf6d4df8877bbea1445e4cbdaa1aa64
