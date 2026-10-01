#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class MinimumRemoveValidParentheses {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> opens;
        vector<bool> remove(s.size(), false);
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') opens.push(i);
            else if (s[i] == ')') {
                if (opens.empty()) remove[i] = true;
                else opens.pop();
            }
        }
        while (!opens.empty()) {
            remove[opens.top()] = true;
            opens.pop();
        }
        string ans;
        for (int i = 0; i < (int)s.size(); ++i) if (!remove[i]) ans += s[i];
        return ans;
    }
};
int main() {
    MinimumRemoveValidParentheses s;
    assert(s.minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de");
    cout << "Passed\n";
    return 0;
}
