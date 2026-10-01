#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class SortColors {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1) ++mid;
            else swap(nums[mid], nums[high--]);
        }
    }
};
int main() {
    SortColors s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    assert((nums == vector<int>{0,0,1,1,2,2}));
    cout << "Passed\n";
    return 0;
}
