#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

using namespace std;

int main() {
  cout << fs::path("/foo/bar.txt").extension() << endl
       << fs::path("/foo/bar.").extension() << endl
       << fs::path("/foo/bar/").extension() << endl
       << fs::path("/foo/bar.png").extension() << endl;
}
