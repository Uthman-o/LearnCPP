#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ReverseWordsInString {
   public:
    string reverseWords(const string& s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string ans;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) ans += " ";
            ans += words[i];
        }

        return ans;
    }
};

int main() {
    ReverseWordsInString s;
    assert(s.reverseWords("  the sky is blue  ") == "blue is sky the");
    cout << "Passed\n";
    return 0;
}
