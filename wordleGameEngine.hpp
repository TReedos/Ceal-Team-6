#pragma once
#include <string>
#include <vector>

class WordleGame {
public:
    WordleGame(const std::string& solution);
    bool guess(const std::string& word);
    std::string getFeedback() const;
    bool isGameOver() const;

private:
    std::string solution;
    std::vector<std::string> guesses;
    std::string feedback;
    bool gameOver;
};