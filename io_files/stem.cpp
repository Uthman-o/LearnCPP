#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

using namespace std;

int main() {
  cout << fs::path("/foo/bar.txt").stem() << endl
       << fs::path("/foo/.bar/").stem() << endl
       << fs::path("/foo/00000.png").stem() << endl;
}
