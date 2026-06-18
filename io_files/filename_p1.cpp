#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

using namespace std;

int main() {
  cout << fs::path("/foo/bar.txt").filename() << endl
       << fs::path("/foo/.bar").filename() << endl
       << fs::path("/foo/bar/").filename() << endl
       << fs::path("/foo/.").filename() << endl
       << fs::path("/foo/..").filename() << endl;
}
