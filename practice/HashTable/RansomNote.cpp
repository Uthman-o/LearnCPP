#include <cassert>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class RansomNote {
   public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        unordered_map<char, int> freq;

        for (char c : magazine) {
            freq[c]++;
        }

        for (char c : ransomNote) {
            if (freq[c] == 0) return false;

            freq[c]--;
        }
        return true;
    }
};

int main() {
    RansomNote R;

    string rN = "aaa";
    string m = "aab";

    bool result = R.canConstruct(rN, m);

    cout << boolalpha << result << endl;

    return 0;
}
