#include <iostream>
#include <string>

using namespace std;

string TypeOf(int) { return "int"; }

string TypeOf(const string &) { return "string"; }

int main(int argc, char const *argv[]) {
  cout << TypeOf(1) << endl;
  cout << TypeOf("hello") << endl;
  return 0;
}
