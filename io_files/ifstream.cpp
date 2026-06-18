#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int i;
  double a, b;
  string s;

  ifstream in("test_cols.txt", ios_base::in);
  while (in >> i >> a >> s >> b) {
    cout << i << ", " << a << ". " << s << ", " << b << endl;
  }
  return 0;
}
