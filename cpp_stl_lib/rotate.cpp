#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3, 3, 4, 4, 3, 7, 8, 9, 10};

  cout << "Before rotate: ";
  for (auto &num : v) {
    cout << num << " ";
  }
  cout << "\n";
  rotate(v.begin(), v.begin() + 5, v.end());

  cout << "After rotate: ";
  for (auto &num : v) {
    cout << num << " ";
  }
  cout << "\n";

  return 0;
}
