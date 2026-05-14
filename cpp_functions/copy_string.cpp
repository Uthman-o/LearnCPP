// #include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  // Commented code is for C

  /*  const char source[] = "Copy this!";
    char dest[5];
    cout << source << '\n';

    strcpy(dest, source);
    cout << dest << '\n';

    // source is const, no problem right ?
    cout << source << '\n';*/

  const string source{"Copy this!"};
  string dest = source;

  cout << source << '\n';
  cout << dest << '\n';

  return 0;
}
