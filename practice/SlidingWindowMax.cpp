#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class SlidingWindowMaximum {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        if (nums.empty() || k <= 0 || k > nums.size()) return {};

        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove index outside of current SlidingWindowMaximum
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window is now completed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    SlidingWindowMaximum S;

    assert(S.maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3) == vector<int>({3, 3, 5, 5, 6, 7}));

    assert(S.maxSlidingWindow({1}, 1) == vector<int>({1}));

    assert(S.maxSlidingWindow({4, 2, 12, 3}, 2) == vector<int>({4, 12, 12}));

    cout << "All tests passed\n";
}
