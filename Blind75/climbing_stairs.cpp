#include <cassert>
#include <iostream>

using namespace std;

class ClimbingStairs {
   public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int step = 3; step <= n; ++step) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    ClimbingStairs s;
    assert(s.climbStairs(2) == 2);
    assert(s.climbStairs(5) == 8);
    cout << "Passed\n";
    return 0;
}
