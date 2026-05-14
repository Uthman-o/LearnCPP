#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

// using namespace std;

double pow(double &x, int &exp) {
  double res = 1.0;
  for (int i = 0; i < exp; i++) {
    res *= x;
  }
  return x;
}

int main(int argc, char const *argv[]) {
  cout << "2.0 ^ 2 = " << pow(2.0, 7) << endl;
  return 0;
}
