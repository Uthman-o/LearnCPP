#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class WordleGame {
   private:
    static constexpr int WORD_LENGTH = 5;
    static constexpr int MAX_ATTEMPTS = 6;

    std::string answer_;
    int attemptsUsed_;
    bool gameOver_;

    bool isValidLength(const std::string& word) const { return word.size() == WORD_LENGTH; }

    std::unordered_map<char, int> buildRemainingCounts(const std::string& guess,
                                                       std::string& feedback) const {
        std::unordered_map<char, int> remaining;

        for (int i = 0; i < WORD_LENGTH; ++i) {
            if (guess[i] == answer_[i]) {
                feedback[i] = '*';
            } else {
                remaining[answer_[i]]++;
            }
        }
        return remaining;
    }

    void markWrongPositionMatches(const std::string& guess, std::string& feedback,
                                  std::unordered_map<char, int>& remaining) const {
        for (int i = 0; i < WORD_LENGTH; ++i) {
            if (feedback[i] == '*') {
                continue;
            }
            char c = guess[i];

            if (remaining[c] > 0) {
                feedback[i] = '+';
                remaining[c]--;
            }
        }
    }

   public:
    explicit WordleGame(const std::string& answer)
        : answer_(answer), attemptsUsed_(0), gameOver_(false) {
        if (!isValidLength(answer_)) {
            throw std::invalid_argument("Answer must be 5 letters");
        }
    }

    std::string getFeedback(const std::string& guess) const {
        if (!isValidLength(guess)) {
            throw std::invalid_argument("Guess must be 5 letters");
        }

        std::string feedback(WORD_LENGTH, '_');

        std::unordered_map<char, int> remaining = buildRemainingCounts(guess, feedback);

        markWrongPositionMatches(guess, feedback, remaining);

        return feedback;
    }

    bool makeGuess(const std::string& guess) {
        if (gameOver_) {
            std::cout << "Game is already over\n";
            return false;
        }

        if (!isValidLength(guess)) {
            std::cout << "Invalid guess. Must be 5 letters. \n";
            return false;
        }

        attemptsUsed_++;

        std::string feedback = getFeedback(guess);

        std::cout << "Guess:   " << guess << "\n";
        std::cout << "Feedback:   " << feedback << "\n";

        if (guess == answer_) {
            std::cout << "You won!\n";
            gameOver_ = true;
            return true;
        }

        if (attemptsUsed_ == MAX_ATTEMPTS) {
            std::cout << "You lost!. The answer was  " << answer_ << "\n";
            gameOver_ = true;
            return false;
        }

        std::cout << "Attempts left:  " << attemptsLeft() << "\n";
        return false;
    }

    int attemptsLeft() const { return MAX_ATTEMPTS - attemptsUsed_; }

    bool isGameOver() const { return gameOver_; }
};

int main() {
    WordleGame game("hello");

    std::cout << "* = correct letter and position\n";
    std::cout << "+ = correct letter, wrong position\n";
    std::cout << "_ = wrong letter\n";

    while (!game.isGameOver()) {
        std::string guess;

        std::cout << "Enter guess:  ";
        std::cin >> guess;

        game.makeGuess(guess);
        std::cout << "\n";
    }

    return 0;
}
