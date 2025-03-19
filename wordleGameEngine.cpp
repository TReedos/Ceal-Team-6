#include "wordleGameEngine.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

WordleGame::WordleGame(const std::string& solution)
    : solution(solution), gameOver(false) {}

bool WordleGame::guess(const std::string& word) {
    if (word.length() != 5 || gameOver) return false;

    guesses.push_back(word);
    feedback.clear();

    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == solution[i]) {
            feedback += 'G'; // Green
        } else if (solution.find(word[i]) != std::string::npos) {
            feedback += 'Y'; // Yellow
        } else {
            feedback += 'B'; // Black
        }
    }

    if (word == solution) {
        gameOver = true;
    }

    return true;
}

std::string WordleGame::getFeedback() const {
    return feedback;
}

bool WordleGame::isGameOver() const {
    return gameOver;
}

int main(int argc, char** argv) {
    WordleGame game("hello");

    while (!game.isGameOver()) {
        std::string guess;
        std::cin >> guess;

        if (!game.guess(guess)) {
            std::cout << "Invalid guess!" << std::endl;
        } else {
            std::cout << game.getFeedback() << std::endl;
        }
    }

    std::cout << "You win!" << std::endl;
    return 0;
}