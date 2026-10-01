#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class SearchInsertPosition {
public:
    int searchInsert(const vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
int main() {
    SearchInsertPosition s;
    assert(s.searchInsert({1,3,5,6}, 5) == 2);
    assert(s.searchInsert({1,3,5,6}, 2) == 1);
    assert(s.searchInsert({1,3,5,6}, 7) == 4);
    cout << "Passed\n";
    return 0;
}
