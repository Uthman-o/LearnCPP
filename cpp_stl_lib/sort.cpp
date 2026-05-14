#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  cout << "Before Sorting: " << endl;

  for (auto &num : s) {
    cout << num << " ";
  }
  cout << "\n";

  sort(s.begin(), s.end());   // Regular sort
  sort(s.rbegin(), s.rend()); // Inverse sort

  cout << "After Sorting: " << endl;

  for (auto &num : s) {
    cout << num << " ";
  }
  cout << "\n";

  return 0;
}
