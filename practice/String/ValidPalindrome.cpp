#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Using the 2 pointer approach

class ValidPalindrome {
   public:
    bool isPlaindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    ValidPalindrome v;
    string s = "racecar";
    cout << "Enter the word:  ";
    cin >> s;

    bool result = v.isPlaindrome(s);
    if (result) {
        cout << s << " is a palindrome " << endl;
    } else {
        cout << s << " is not a palindrome " << endl;
    }

    return 0;
}
