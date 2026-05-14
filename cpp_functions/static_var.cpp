#include <iostream>

using namespace std;

void f() {
  static int counter_s = 0;
  int counter = 0;

  cout << "Counter State " << ++counter << endl;
  cout << "Static Counter State " << ++counter_s << endl;
}

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 5; i++) {
    f();
  }
  return 0;
}
