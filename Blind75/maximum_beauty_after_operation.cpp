#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class MaximumBeautyAfterOperation {
   public:
    int maximumBeauty(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int best = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                ++left;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};

int main() {
    MaximumBeautyAfterOperation s;
    vector<int> nums = {4, 6, 1, 2};
    assert(s.maximumBeauty(nums, 2) == 3);

    cout << "Passed\n";
    return 0;
}
