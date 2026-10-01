#include <cassert>
#include <iostream>

using namespace std;

class PalindromeNumber {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    PalindromeNumber s;
    assert(s.isPalindrome(121));
    assert(!s.isPalindrome(-121));
    assert(!s.isPalindrome(10));
    cout << "Passed\n";
    return 0;
}
