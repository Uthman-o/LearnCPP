#include <chrono>
#include <iostream>

using namespace std;

int fibonnaci(int x) {
  if (x <= 1)
    return x;

  int a = 0;
  int b = 1;
  for (int i = 2; i <= x; i++) {
    int next = a + b;
    a = b;
    b = next;
  }
  return b;
}

int main(int argc, char const *argv[]) {
  auto start = chrono::steady_clock::now();
  int fib = fibonnaci(42);
  cout << fib << endl;
  auto end = chrono::steady_clock::now();

  chrono::duration<double> sec = end - start;
  cout << "elapsed time " << sec.count() << endl;
  return 0;
}
