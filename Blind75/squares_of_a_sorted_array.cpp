#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class SquaresOfSortedArray {
   public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());

        for (int i = nums.size() - 1; i >= 0; --i) {
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];

            if (l > r) {
                ans[i] = l;
                ++left;
            } else {
                ans[i] = r;
                --right;
            }
        }
        return ans;
    }
};

int main() {
    SquaresOfSortedArray s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> expected = {0, 1, 9, 16, 100};
    assert(s.sortedSquares(nums) == expected);
    cout << "Passed\n";
    return 0;
}
