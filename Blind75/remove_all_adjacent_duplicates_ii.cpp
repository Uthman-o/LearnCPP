#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class RemoveAllAdjacentDuplicatesII {
public:
    string removeDuplicates(const string& s, int k) {
        vector<pair<char,int>> st;
        for (char c : s) {
            if (!st.empty() && st.back().first == c) ++st.back().second;
            else st.push_back({c,1});
            if (st.back().second == k) st.pop_back();
        }
        string ans;
        for (auto [c,count] : st) ans.append(count, c);
        return ans;
    }
};
int main() {
    RemoveAllAdjacentDuplicatesII s;
    assert(s.removeDuplicates("deeedbbcccbdaa", 3) == "aa");
    cout << "Passed\n";
    return 0;
}
