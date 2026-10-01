#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ValidAnagram {
   public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;

        // Using Hashtable / unordered_map
        //  unordered_map<char, int> count;
        //
        //  for (char c : s) count[c]++;
        //  for (char c : t) {
        //      if (--count[c] < 0) return false;
        //  }

        // Using simple vector. Brute force.
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int x : count) {
            if (x != 0) return false;
        }

        return true;
    }
};

int main() {
    ValidAnagram v;
    string s = "anagram";
    string t = "nagara";
    cout << "Enter first word:  ";
    cin >> s;
    cout << "Enter second word:  ";
    cin >> t;

    bool result = v.isAnagram(s, t);
    if (result) {
        cout << t << " is an anagram of " << s << endl;
    } else {
        cout << t << " is not an anagram of " << s << endl;
    }
    // cout << boolalpha << result << endl;

    return 0;
}
