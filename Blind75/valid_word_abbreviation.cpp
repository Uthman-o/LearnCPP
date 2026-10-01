#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class ValidWordAbbreviation {
   public:
    bool validWordAbbreviation(const string& word, const string& abbr) {
        int i = 0;
        int j = 0;

        while (i < word.size() && j < abbr.size()) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                ++i;
                ++j;
            } else {
                if (abbr[j] == '0') return false;

                int number = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    number = number * 10 + (abbr[j] - '0');
                    ++j;
                }

                i += number;
            }
        }

        return i == word.size() && j == abbr.size();
    }
};

int main() {
    ValidWordAbbreviation s;
    assert(s.validWordAbbreviation("internationalization", "i12iz4n"));
    assert(!s.validWordAbbreviation("apple", "a2e"));
    cout << "Passed\n";
    return 0;
}
