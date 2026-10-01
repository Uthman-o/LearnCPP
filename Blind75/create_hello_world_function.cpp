#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class CreateHelloWorldFunction {
   public:
    string helloWorld() {
        return "Hello World";
    }
};

int main() {
    CreateHelloWorldFunction s;
    assert(s.helloWorld() == "Hello World");
    cout << s.helloWorld() << '\n';
    return 0;
}
