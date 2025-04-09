#include "wordleGameEngine.hpp"

std::string Wordle::getRandomWord() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, wordList.size() - 1);
	return wordList[dist(gen)];
}

Wordle::Wordle(const std::string& wordFile) {
	loadWordsFromFile(wordFile);
	if(!wordList.empty()) {
	  targetWord = getRandomWord();
	} else {
	  throw std::runtime_error("Word list is empty or invalid.");
	}
}

std::string Wordle::evaluateGuess(const std::string& guess) {
	std::string feedback = "_____";
	std::unordered_multiset<char> wordSet(targetWord.begin(), targetWord.end());

	for (size_t i = 0; i < guess.size(); ++i) {
	  if (guess[i] == targetWord[i]) {
	    feedback[i] = 'G';
	    wordSet.erase(wordSet.find(guess[i]));
	  }
	}

	for (size_t i = 0; i < guess.size(); ++i) {
	  if (feedback[i] == '_' && wordSet.count(guess[i])) {
	    feedback[i] = 'Y';
	    wordSet.erase(wordSet.find(guess[i]));
	  } else if (feedback[i] == '_') {
	    feedback[i] = 'X';
	  }
	}

	return feedback;
}

void Wordle::play() {
	std::cout << "Welcome to Wordle! Guess a 5-letter word." << std::endl;
	int attempts = 0;
	std::string guess;

	while(attempts < maxAttempts) {
	  std::cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ": ";
	  std::cin >> guess;

	  if(guess.size() != 5) {
	    std::cout << "Invalid input! Enter a 5-letter word." << std::endl;
	    continue;
	  }

	  std::string feedback = evaluateGuess(guess);
	  std::cout << "Feedback: " << feedback << std::endl;

	  if (feedback == "GGGGG") {
	    std::cout << "Congratulations! You guessed the word!" << std::endl;
	    return;
	  }

	  ++attempts;
	}

	std::cout << "Game Over! The word was: " << targetWord << std::endl;
}

void Wordle::loadWordsFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string word;
	while (file >> word) {
	  if (word.length() == 5) {
	    wordList.push_back(word);
	  }
	}
}
