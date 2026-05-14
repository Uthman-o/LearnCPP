#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

int main() {

  vector<int> numbers = {1, 2, 3};
  vector<string> names = {"Uthman", "Zainab"};

  names.emplace_back("Adeola");
  numbers.reserve(1000);

  // sort(names.begin(), names.end());

  for (const auto &name : names) {
    cout << "Name is " << name << endl;
  }

  cout << "First name : " << names.front() << endl;
  cout << "Last name : " << names.back() << endl;
  cout << "Capacity : " << numbers.capacity() << endl;
  cout << "Size of numbers : " << numbers.size() << endl;
  cout << "Size of names : " << names.size() << endl;

  return 0;
}
