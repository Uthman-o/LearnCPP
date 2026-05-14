#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc > 3) {
    cerr << "[ERROR] Too many arguments provided\n";
    return 1;
  }

  int num1 = 0;
  int num2 = 0;
  string ext1;
  string ext2;

  stringstream ss1(argv[1]);
  stringstream ss2(argv[2]);

  ss1 >> num1 >> ext1;
  ss2 >> num2 >> ext2;

  if (ext1 == ".txt" && ext2 == ".txt") {
    double mean_val = (num1 + num2) / 2.0;
    cout << mean_val << '\n' << endl;
  } else if (ext1 == ".png" && ext2 == ".png") {
    int sum = num1 + num2;
    cout << sum << '\n' << endl;
  } else if (ext1 == ".txt" && ext2 == ".png") {
    int mod = num1 % num2;
    cout << mod << '\n' << endl;
  } else {
    cerr << "[ERROR] Wrong filetype\n";
    return 2;
  }
}
