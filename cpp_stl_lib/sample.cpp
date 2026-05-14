#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>

using namespace std;

int main() {
  string in = "C++ is cool", out;
  auto rnd_dev = mt19937{random_device{}()};
  const int kNLetters = 5;
  sample(in.begin(), in.end(), back_inserter(out), kNLetters, rnd_dev);

  cout << "from : " << in << endl;
  cout << "sample : " << out << endl;

  return 0;
}
