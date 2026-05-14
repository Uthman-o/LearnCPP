#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto UpperCase(char c) { return toupper(c); }

int main() {
  const string s("hello");
  string ns("hello");
  string S{s};
  transform(s.begin(), s.end(), S.begin(), UpperCase);

  cout << s << endl;
  cout << S << endl;

  for (char &c : ns) {
    c = toupper(static_cast<unsigned char>(c));
    cout << c << "";
  }

  cout << '\n';

  return 0;
}
