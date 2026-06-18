#include <iostream>
#include <string>

using namespace std;

void Print(const string& str) { cout << "lvalue: " << str << endl; }

void Print(string&& str) { cout << "rvalue: " << str << endl; }

int main() {
    string hello = "hi";
    Print(hello);
    Print("world");
    Print(std::move(hello));

    return 0;
}
