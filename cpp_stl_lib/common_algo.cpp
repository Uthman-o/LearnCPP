#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

  std::cout << "Sum: " << std::accumulate(v.begin(), v.end(), 0) << "\n";
  std::cout << "Min: " << *std::min_element(v.begin(), v.end()) << "\n";
  std::cout << "Max: " << *std::max_element(v.begin(), v.end()) << "\n";
  std::cout << "Evens: " << std::count_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;
  }) << "\n";

  std::sort(v.begin(), v.end());
  std::cout << "Sorted: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "Contains 7? " << std::boolalpha
            << std::binary_search(v.begin(), v.end(), 7) << "\n";
}
