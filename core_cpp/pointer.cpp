#include <iostream>

void increment(int *p) { (*p)++; }

int main() {
  // Basics
  int x = 42;
  int *ptr = &x;
  std::cout << "x = " << x << "\n";
  std::cout << "address of x = " << ptr << "\n";
  std::cout << "*ptr = " << *ptr << "\n";

  *ptr = 100;
  std::cout << "after *ptr = 100, x = " << x << "\n";

  // Function modifying through pointer
  increment(&x);
  std::cout << "after increment, x = " << x << "\n";

  // Arrays and pointer arithmetic
  int arr[4] = {10, 20, 30, 40};
  int *p = arr;

  std::cout << "Init pointer : " << *p << '\n';
  std::cout << "\nArray traversal:\n";
  for (int i = 0; i < 4; ++i) {
    std::cout << "  arr[" << i << "] = " << *(p + i) << "\n";
  }

  // Null pointer check
  int *maybe = nullptr;
  if (maybe == nullptr) {
    std::cout << "\nmaybe is null, not dereferencing.\n";
  }

  // Dynamic allocation
  int *heap = new int(999);
  std::cout << "heap value: " << *heap << "\n";
  delete heap;
  heap = nullptr;

  return 0;
}
