/*Game.cc
*/

#include "Game.hh"
#include "BSTB.hh"
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Game::Game() {
	//liz
}
Game::Game(string infile) {
	//liz
}

void Game::startGame() {
	wordlist = new BSTB();
	string input0 = "";
	int input = 0;
	while (input0 != "-1") {
		
		srand(time(NULL));
		cout << "How many letters would you like?" << endl;
		cin >> input;
		cout << "Your letters are: ";
		cout << getLetters(input) << endl;
		cout << endl << "Please enter the words you would like to guess: " << endl;
		cin >> input0;

	}

}

void Game::readTreeFromFile(string dictfile) {
	dict = new BSTB();
	ifstream file(dictfile.c_str());
	string word;
	while (!file.eof()) {
		file >> word;
		if (!file.eof()) {
			dict->insert(word);
		}
	}
	return;
}

char* Game::getLetters(int x) {
	const char allLetters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char* Alphabets = new char[x];
	int RandIndex;
	int constCount = 0;
	for (int i = x; i = 0; i--) {
		RandIndex = rand() % 26;
		Alphabets[i] = allLetters[RandIndex];
	}
	for (int j = x; j = 0; j--) {
		if (Alphabets[j] != ('a' || 'e' || 'i' || 'o' || 'u')) {
			constCount += 1;
		}
	}
	if (x - constCount != 0) {
		char vowels[] = { 'a','e','i','o','u' };
		int randNum = rand() % 5;
		Alphabets[0] = vowels[randNum];
	}
	return Alphabets;
}
void Game::getWords() {
	//liz
}
bool Game::checkWLetters(string s) {
	//liz
}
void Game::checkWordsForScore(){

}

