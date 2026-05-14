#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
  std::vector<int> v = {3, 1, 4, 1, 5};
  std::set<int> s(v.begin(), v.end()); // unique + sorted
  std::map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}};

  ages["Debby"] = 28;
  ages["David"] = 30;

  std::cout << "Vector: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\nSet:    ";
  for (int x : s)
    std::cout << x << " ";
  std::cout << "\nMap:\n";
  for (auto &[name, age] : ages)
    std::cout << "  " << name << " -> " << age << "\n";
}
