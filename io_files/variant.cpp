#include <iostream>
#include <utility>
#include <variant>

using namespace std;

int main(int argc, char const *argv[]) {

  variant<int, float> v1;
  v1 = 12;
  cout << get<int>(v1) << endl;

  variant<int, float> v2{3.14F};

  cout << get<1>(v2) << endl;

  v2 = get<int>(v1);
  v2 = get<0>(v1);
  v2 = v1;

  cout << get<int>(v2) << endl;
  return 0;
}
