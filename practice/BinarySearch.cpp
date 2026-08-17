#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
   public:
    int bruteSearch(const vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int optimalSearch(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    BinarySearch B;

    // int result = B.bruteSearch(nums, target);
    int result = B.optimalSearch(nums, target);

    cout << boolalpha << (result == -1) << endl;
    return 0;
}
