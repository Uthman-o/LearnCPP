#include <iostream>
using namespace std;

// Never return a reference to a varible local to the scope. Terrible Pratice

int &MultiplyBy10(int num) {
  int retval = 0;
  retval = 10 * num;
  cout << "retval is " << retval << endl;
  return retval;
}

int main(int argc, char const *argv[]) {
  int out = MultiplyBy10(10);
  cout << "out is " << out << '\n';
  return 0;
}
