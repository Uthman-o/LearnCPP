#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>


/***********************************************
Problem type: Dynamic programming
Container: none
Time: O(n)
Space: O(1)

Important: track both maximum and minimum products because a negative number can turn the minimum into the maximum.
****************************************************/
using namespace std;

class MaxProductSubArray{
public:
  int maxProduct(const vector<int>& nums){
    if(nums.empty()) return 0;


    int currentMax = nums[0];
    int currentMin = nums[0];
    int answer = nums[0];


    for (int i = 0; i< nums.size(); ++i){
      //Negative swaps max/min behaviour

      if (nums[i] < 0){
        swap(currentMax, currentMin);
      }

      currentMax = max(nums[i], currentMax* nums[i]);
      currentMin = min(nums[i], currentMin * nums[i]);

      answer = max(answer, currentMax);
    }
    cout<< answer;
    return answer;
  }
};



int main() {
  MaxProductSubArray solver;

 assert(solver.maxProduct({2,3,-2,4}) == 6);
 assert(solver.maxProduct({-2,0,-1}) == 0);
 assert(solver.maxProduct({-2,3,-4}) == 24);
 assert(solver.maxProduct({5}) == 5);
 assert(solver.maxProduct({-2}) == -2);
 assert(solver.maxProduct({0,2}) == 2);

 cout << "All tests passed\n";
  return 0;
}
