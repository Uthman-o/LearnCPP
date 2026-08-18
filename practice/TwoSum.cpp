#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TwoSum {
   public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
                //  return nums
                //return {complement, nums[i]};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    TwoSum t;

    vector<int> nums = {1, 3, 4, 6, 2, 7, 8, 5, 9};
    int target = 11;

    vector<int> indices = t.twoSum(nums, target);

    cout << "Index " << indices[0] << " and " << indices[1] << endl;

    return 0;
}
