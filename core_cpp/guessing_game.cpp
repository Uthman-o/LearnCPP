#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 99);

  int rand_num = dist(gen);

  int guess = 0;

  while (guess != rand_num) {
    cout << "Enter your guess \n" << endl;
    cin >> guess;

    if (guess < 0 || guess > 99) {
      cerr << "[WARNING] Number must be between 0 and 99 \n" << endl;
    } else if (guess == rand_num) {
      cout << "Congratulations, you've won.\n The random number is " << rand_num
           << endl;
    } else if (guess > rand_num) {
      cout << "The number is smaller \n" << endl;
    } else {
      cout << "The number is larger \n" << endl;
    }
  }
  return 0;
}
