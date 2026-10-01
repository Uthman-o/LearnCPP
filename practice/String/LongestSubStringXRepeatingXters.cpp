#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// Sliding Window
using namespace std;

class LongestSubstring {
   public:
    int lengthOfLongestSubstring(const string& s) {
        vector<int> charIndex(128, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            if (charIndex[c] >= left) {
                left = charIndex[c] + 1;
            }

            charIndex[c] = right;

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    LongestSubstring L;

    string s = "abcabcbb";

    int mL = L.lengthOfLongestSubstring(s);

    cout << " Maximum Length of Substring is " << mL << endl;

    return 0;
}
