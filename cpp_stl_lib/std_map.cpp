#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
  using StudentList = map<int, string>;

  StudentList cpp_students;
  StudentList cpp_grads;

  cpp_grads.emplace(1565, "Adeola");
  cpp_grads.emplace(5692, "David");
  cpp_grads.emplace(1738, "Debby");

  cpp_students.emplace(1509, "Nacho");
  cpp_students.emplace(1040, "Pape");
  cpp_students.emplace(8820, "Marcelo");

  for (const auto &[id, name] : cpp_students) {
    cout << "id: " << id << " , " << name << endl;
  }

  for (const auto &[id, name] : cpp_grads) {
    cout << "id: " << id << " , " << name << endl;
  }

  return 0;
}
