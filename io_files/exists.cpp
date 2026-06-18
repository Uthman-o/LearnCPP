#include <filesystem>
#include <fstream>
#include <iostream>
namespace fs = std::filesystem;

using namespace std;

void demo_exists(const fs::path &p) {
  cout << p;
  if (fs::exists(p))
    cout << " exists\n";
  else
    cout << " does not exist\n";
}

int main() {
  fs::create_directory("sandbox");
  ofstream("sandbox/file");
  demo_exists("sandbox/file");
  demo_exists("sandbox/cache");
  demo_exists("stem.cpp");
  fs::remove_all("sandbox");

  return 0;
}
