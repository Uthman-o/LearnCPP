#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string s = "Nacho";
  const int N = 5;
  vector<int> vec;
  vec.reserve(N);

  for (int i = 0; i < N; ++i) {
    vec.emplace_back(i);
    cout << "Element " << vec[i] << endl;
  }

  vector<int> vec2;

  for (int i = 0; i < N; ++i) {
    vec2.emplace_back(i);
    cout << " Vec 2 Element " << vec2[i] << endl;
  }

  cout << "Size of string " << s.size() << endl;
  s.pop_back();
  cout << "Swapped String " << s << endl;

  return 0;
}
