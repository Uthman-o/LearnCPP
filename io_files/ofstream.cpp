#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  string filename = "out.txt";
  ofstream outfile(filename);

  if (!outfile.is_open())
    return EXIT_FAILURE;

  double a = 1.23123123;
  outfile << "Just a random string" << endl;
  outfile << setprecision(20) << a << endl;
  return 0;
}
