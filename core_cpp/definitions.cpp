#include <iostream>

int main() {
  std::std::map<char, int> my_dict{{'a', 27}, {'b', 3}};
  for (const auto &[key, value] : mydict) {
    std::cout << key << "has value" << value << '\n';
  }
  return 0;
}
