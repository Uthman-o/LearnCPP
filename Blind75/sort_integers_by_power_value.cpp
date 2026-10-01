#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class SortIntegersByPowerValue {
   private:
    unordered_map<int, int> memo{{1, 0}};

    int power(int x) {
        if (memo.count(x)) return memo[x];
        if (x % 2 == 0) return memo[x] = 1 + power(x / 2);
        return memo[x] = 1 + power(3 * x + 1);
    }

   public:
    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int x = lo; x <= hi; ++x) nums.push_back(x);

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int pa = power(a);
            int pb = power(b);
            if (pa == pb) return a < b;
            return pa < pb;
        });

        return nums[k - 1];
    }
};

int main() {
    SortIntegersByPowerValue s;
    assert(s.getKth(12, 15, 2) == 13);
    cout << "Passed\n";
    return 0;
}
