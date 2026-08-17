#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Anagram {
   public:
    // void checkAnagram(string& word1, string& word2) {
    //     string temp1 = word1;
    //     string temp2 = word2;
    //
    //     for (char& c : word1) {
    //         c = std::tolower(c);
    //     }
    //
    //     for (char& c : word2) {
    //         c = std::tolower(c);
    //     }
    //
    //     sort(word1.begin(), word1.end());
    //     sort(word2.begin(), word2.end());
    //
    //     if (word1 == word2) {
    //         cout << "The strings are anagrams : " << temp1 << " " << temp2 << endl;
    //     } else {
    //         cout << "Not anagrams : " << temp1 << " " << temp2 << endl;
    //     }
    // }

    bool checkAnagram(const string& word1, const string& word2) {
        if (word1.size() != word2.size()) return false;

        array<int, 256> count{};

        for (size_t i = 0; i < word1.size(); ++i) {
            unsigned char c1 = static_cast<unsigned char>(word1[i]);
            unsigned char c2 = static_cast<unsigned char>(word2[i]);

            count[tolower(c1)]++;
            count[tolower(c2)]--;
        }

        for (int value : count) {
            if (value != 0) return false;
        }

        return true;
    }
};

int main() {
    Anagram A;

    string f1;
    string f2;
    cout << "Enter first word :   ";
    cin >> f1;

    cout << "Enter second word :   ";
    cin >> f2;

    if (A.checkAnagram(f1, f2)) {
        cout << "The strings are anagrams : " << f1 << " " << f2 << endl;
    } else {
        cout << "Not anagrams : " << f1 << " " << f2 << endl;
    }

    // string f1 = "abcfed";
    // string f2 = "cfdabe";

    // A.checkAnagram(f1, f2);

    return 0;
}
