#include <array>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
class ValidAnagram {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        array<int,26> count{};
        for (char c : s) ++count[c - 'a'];
        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};
int main() {
    ValidAnagram s;
    assert(s.isAnagram("anagram", "nagaram"));
    assert(!s.isAnagram("rat", "car"));
    cout << "Passed\n";
    return 0;
}
