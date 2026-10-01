#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class MaximumSubarray {
   public:
    int maxSubArray(const vector<int>& nums) {
        int current = nums[0];
        int best = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }

        return best;
    }
};

int main() {
    MaximumSubarray s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(s.maxSubArray(nums) == 6);

    cout << "Passed\n";
    return 0;
}
