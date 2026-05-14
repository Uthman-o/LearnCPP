#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

  const int n1 = 3;
  const int n2 = 5;
  int num_items1 = count(v.begin(), v.end(), n1);
  int num_items2 = count(v.begin(), v.end(), n2);

  cout << n1 << " count: " << num_items1 << endl;
  cout << n2 << " count: " << num_items2 << endl;

  return 0;
}
