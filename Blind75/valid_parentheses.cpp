#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class ValidParentheses {
   public:
    bool isValid(const string& s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    ValidParentheses s;
    assert(s.isValid("()[]{}"));
    assert(!s.isValid("(]"));
    cout << "Passed\n";
    return 0;
}
