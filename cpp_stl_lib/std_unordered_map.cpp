#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main() {
  using StudentList = unordered_map<int, string>;
  using StudentListC = unordered_map<char, string>;

  StudentList cpp_students;
  StudentListC cpp_grads;

  unordered_map<char, int> my_dict{{'a', 27}, {'b', 3}};

  my_dict['c'] = 9;

  cpp_grads.emplace('a', "Adeola");
  cpp_grads.emplace('b', "David");
  // cpp_grads.emplace('c', "Debby");
  cpp_grads['c'] = "Debby";

  cpp_students.emplace(1509, "Nacho");
  cpp_students.emplace(1040, "Pepe");
  cpp_students.emplace(8820, "Marcelo");

  for (const auto &[id, name] : cpp_students) {
    cout << "id: " << id << " , " << name << endl;
  }

  for (const auto &[id, name] : cpp_grads) {
    cout << "id: " << id << " , " << name << endl;
  }

  for (const auto &[k, v] : my_dict) {
    cout << k << " has value " << v << endl;
  }

  return 0;
}
