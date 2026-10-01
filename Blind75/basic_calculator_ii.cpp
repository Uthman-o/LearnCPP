#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
class BasicCalculatorII {
public:
    int calculate(const string& s) {
        vector<long long> st;
        long long num = 0;
        char op = '+';
        for (int i = 0; i <= (int)s.size(); ++i) {
            char c = i < (int)s.size() ? s[i] : '+';
            if (isdigit(c)) num = num * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == (int)s.size()) {
                if (op == '+') st.push_back(num);
                else if (op == '-') st.push_back(-num);
                else if (op == '*') st.back() *= num;
                else if (op == '/') st.back() /= num;
                op = c;
                num = 0;
            }
        }
        long long total = 0;
        for (long long x : st) total += x;
        return (int)total;
    }
};
int main() {
    BasicCalculatorII s;
    assert(s.calculate("3+2*2") == 7);
    assert(s.calculate(" 3/2 ") == 1);
    assert(s.calculate(" 3+5 / 2 ") == 5);
    cout << "Passed\n";
    return 0;
}
