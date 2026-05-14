#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int n1 = 3;
  vector<int> v{0, 1, 2, 3, 4};

  auto result1 = find(v.begin(), v.end(), n1);

  if (result1 != end(v)) {
    cout << " v contains: " << n1 << endl;
  } else {
    cout << "v does not contain: " << n1 << endl;
  }
  return 0;
}
