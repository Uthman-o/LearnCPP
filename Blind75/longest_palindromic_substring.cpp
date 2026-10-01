#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class LongestPalindromicSubstring {
   private:
    pair<int, int> expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - left - 1};
    }

   public:
    string longestPalindrome(const string& s) {
        if (s.empty()) return "";

        int bestStart = 0;
        int bestLen = 1;

        for (int i = 0; i < s.size(); ++i) {
            auto [start1, len1] = expand(s, i, i);
            auto [start2, len2] = expand(s, i, i + 1);

            if (len1 > bestLen) {
                bestStart = start1;
                bestLen = len1;
            }

            if (len2 > bestLen) {
                bestStart = start2;
                bestLen = len2;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};

int main() {
    LongestPalindromicSubstring s;
    string ans = s.longestPalindrome("babad");
    assert(ans == "bab" || ans == "aba");
    assert(s.longestPalindrome("cbbd") == "bb");
    cout << "Passed\n";
    return 0;
}
