#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char const *argv[]) {
    int a = 3;
    int b = 5;

    cout << a << ' ' << b << '\n';

    swap(a, b);

    cout << a << ' ' << b << endl;
    return 0;
}
