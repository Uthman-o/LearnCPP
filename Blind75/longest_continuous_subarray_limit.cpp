#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class LongestContinuousSubarray {
   public:
    int longestSubarray(const vector<int>& nums, int limit) {
        deque<int> maxD;
        deque<int> minD;
        int left = 0;
        int best = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!maxD.empty() && nums[maxD.back()] < nums[right]) maxD.pop_back();
            while (!minD.empty() && nums[minD.back()] > nums[right]) minD.pop_back();

            maxD.push_back(right);
            minD.push_back(right);

            while (nums[maxD.front()] - nums[minD.front()] > limit) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                ++left;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};

int main() {
    LongestContinuousSubarray s;
    vector<int> nums = {8, 2, 4, 7};
    assert(s.longestSubarray(nums, 4) == 2);
    cout << "Passed\n";
    return 0;
}
