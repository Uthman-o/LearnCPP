#include <array>
#include <iostream>
#include <typeinfo>

using std::array;
using std::boolalpha;
using std::cout;
using std::endl;

int main() {
  array<int, 5> data{1, 2, 3, 4, 5};

  for (const auto &elem : data) {
    cout << elem << endl;
  }

  cout << boolalpha;
  cout << "Array empty: " << data.empty() << endl;
  cout << "Array size: " << data.size() << endl;
  cout << "data type : " << typeid(data[1]).name() << endl;

  return 0;
}
