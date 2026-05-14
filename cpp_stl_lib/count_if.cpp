#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline bool div_by_3(int i) { return i % 3 == 0; }

int main() {
  vector<int> v{1, 2, 3, 3, 4, 4, 3, 7, 8, 9, 10};

  int n3 = count_if(v.begin(), v.end(), div_by_3);

  cout << " # divisible by 3: " << n3 << endl;

  return 0;
}
