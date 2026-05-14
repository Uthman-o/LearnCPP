#include <iostream>
#include <map>

int main() {
  std::map<char, int> my_dict{{'a', 27}, {'b', 3}};

  for (const auto &[key, value] : my_dict) {
    std::cout << key << "  has value  " << value << '\n';
  }

  return 0;
}
