#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>


using namespace std;


class WordleGame{

private:
  string answer_;
  const int kWordLength = 5;

public:
  explicit WordleGame(const string& answer) : answer_(answer) {
    if (answer_.size() != kWordLength) {
        throw invalid_argument("Answer must be 5 letters");
    };
  }
  void solve (const string& guess){
    if (guess.size() != kWordLength) {
        throw invalid_argument("Guess must be 5 letters");
    }
      string feedback(kWordLength,'_');

      unordered_map<char, int> remaining;

      for (int i = 0; i<kWordLength; ++i){
        if (guess[i] == answer_[i] ) {
          feedback[i] = '*';
        } else {
          remaining[answer_[i]]++;
        }
      }


      for (int i = 0; i<kWordLength ; i++){
        if(feedback[i] == '*') continue;

        char c = guess[i];

        if(remaining[c] >0) {
          feedback[i] = '+';
          remaining[c]--;
        }
      }

      cout << "Guess:  " << guess << "\nFeedback: " << feedback << endl;
  }
};

int main(){
  WordleGame W("hello");

  W.solve("world");
  W.solve("wolld");
  W.solve("wollo");
  W.solve("hollo");
  W.solve("hello");



  return 0;
}
