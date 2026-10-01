#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class RemoveElement {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int x : nums) if (x != val) nums[write++] = x;
        return write;
    }
};
int main() {
    RemoveElement s;
    vector<int> nums={3,2,2,3};
    int k=s.removeElement(nums,3);
    assert(k==2 && nums[0]==2 && nums[1]==2);
    cout << "Passed\n";
    return 0;
}
