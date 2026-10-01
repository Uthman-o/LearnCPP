#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class WordBreak {
   public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int end = 1; end <= s.size(); ++end) {
            for (int start = 0; start < end; ++start) {
                if (dp[start] && words.count(s.substr(start, end - start))) {
                    dp[end] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    WordBreak s;
    vector<string> dict = {"leet", "code"};
    assert(s.wordBreak("leetcode", dict));
    cout << "Passed\n";
    return 0;
}
