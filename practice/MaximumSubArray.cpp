#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/*********************************************
Kadane's Algorithm
Problem type: Dynamic programming / Kadane's algorithm
Container: no extra container needed
Time: O(n)
Space: O(1)
******************************************/
class MaxSubArray{
public:
  int maxSubArray (const vector<int>& nums) {
    if(nums.empty()) return 0;

    int currentSum = nums[0];
    int maxSum = nums[0];


    for (int i =1; i < nums.size(); ++i){
      currentSum = max(nums[i], currentSum + nums[i]);
      maxSum = max(maxSum, currentSum);
    }

    return maxSum;
  }

};

int main(){
  MaxSubArray solver;

    assert(solver.maxSubArray(
        {-2,1,-3,4,-1,2,1,-5,4}
    ) == 6);

    assert(solver.maxSubArray({1}) == 1);

    assert(solver.maxSubArray({5,4,-1,7,8}) == 23);

    // Important edge case: all negative
    assert(solver.maxSubArray({-5,-2,-8}) == -2);

    assert(solver.maxSubArray({-2,1}) == 1);

    cout << "All tests passed\n";

  return 0;
}
