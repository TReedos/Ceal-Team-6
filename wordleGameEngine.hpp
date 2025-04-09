#ifndef WORDLE_H
#define WORDLE_H

#include<iostream>
#include<vector>
#include<string>
#include<random>
#include<unordered_set>
#include<fstream>

class Wordle {
private:
	std::vector<std::string> wordList;
	std::string targetWord;
	int maxAttempts = 6;
	std::string getRandomWord();
	void loadWordsFromFile(const std::string& filename);
public:
	Wordle(const std::string& wordFile);
	std::string evaluateGuess(const std::string& guess);
	void play();
	
};

#endif
