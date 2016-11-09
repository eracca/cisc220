/*PartBParagraphs.hh
*/
//Allan Chandy & Liz Racca

#ifndef PARTBPARAGRAPHS_HH_
#define PARTBPARAGRAPHS_HH_

#include "PartBBSTB.hh"
#include <string>

class Game {
	PartBBSTB *words;
	char *currletters;
public:
	string convertChar(char letters); //Converts letters grouped together to string 
	BSTB convertText(string paragraph); //This would be where you input a string of text and it would return a binary tree of nodes
	void detectGroup(); // Detects words that are grouped together until the keys are released
	void delWords(BSTB n); // Delete words that are stored in the tree 
	void undoDelete(BSTB n); // undos deleted words 

};

#endif