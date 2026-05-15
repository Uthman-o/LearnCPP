#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  tuple<double, char, string, vector<int>> student1;
  using Student = tuple<double, char, string, vector<int>>;
  Student student2{1.4, 'A', "Jose", {1, 2, 3, 4}};
  cout << get<double>(student2) << endl;
  cout << get<string>(student2) << endl;
  vector<int> nums = get<vector<int>>(student2);

  for (int x : nums) {
    cout << x << " ";
  }

  cout << endl;
  return 0;
}
