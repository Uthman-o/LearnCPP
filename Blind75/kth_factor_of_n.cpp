#include <cassert>
#include <iostream>

using namespace std;

class KthFactorOfN {
   public:
    int kthFactor(int n, int k) {
        for (int factor = 1; factor <= n; ++factor) {
            if (n % factor == 0) {
                --k;
                if (k == 0) return factor;
            }
        }
        return -1;
    }
};

int main() {
    KthFactorOfN s;
    assert(s.kthFactor(12, 3) == 3);
    assert(s.kthFactor(7, 2) == 7);
    assert(s.kthFactor(4, 4) == -1);
    cout << "Passed\n";
    return 0;
}
