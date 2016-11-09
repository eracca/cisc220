/*Game.hh
*/
//Allan Chandy & Liz Racca

#ifndef GAME_HH_
#define GAME_HH_

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