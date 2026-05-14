#include <cstdint>
#include <iostream>
#include <typeinfo>

int main() {
  int age = 25;
  double pi = 3.14159;
  char grade = 'A';
  bool active = true;

  const int MAX = 100;
  constexpr double E = 2.71828;

  auto x = 42;   // deduced as int
  auto y = 3.14; // deduced as double

  int32_t fixed = 1000; // exactly 32 bits

  // Conversion examples
  double d = 9.8;
  int truncated = static_cast<int>(d); // 9

  std::cout << "age: " << age << "\n";
  std::cout << "pi: " << pi << "\n";
  std::cout << "grade: " << grade << "\n";
  std::cout << "active: " << std::boolalpha << active << "\n";
  std::cout << "MAX: " << MAX << ", E: " << E << "\n";
  std::cout << "auto x: " << x << ", auto y: " << y << "\n";
  std::cout << "truncated " << d << " to " << truncated << "\n";

  // Sizes on this platform
  std::cout << "\nSizes (bytes):\n";
  std::cout << "  int: " << sizeof(int) << "\n";
  std::cout << "  long: " << sizeof(long) << "\n";
  std::cout << "  double: " << sizeof(double) << "\n";
  std::cout << "  bool: " << sizeof(bool) << "\n";
}
