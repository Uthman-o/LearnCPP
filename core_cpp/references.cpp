#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int num = 42;
  int &ref = num;
  const int &kRef = num;
  ref = 0;
  cout << ref << "  " << num << "  " << kRef << endl;
  num = 42;
  cout << ref << "  " << num << "  " << kRef << endl;
  return 0;
}
