#include <iostream>
#include <vector>
#include <cassert>


/****************************************************
Problem type: Prefix/suffix products
Container: output vector<int>
Time: O(n)
Extra space: O(1) excluding output
******************************************************/

using namespace std;

class ProductExceptSelf{
public:
  vector<int> productExceptSelf(const vector<int>& nums){
    int n = nums.size();
    vector<int> answer(n,1);

    int prefix = 1;

    for (int i = 0; i<n ; ++i) {
      answer[i] = prefix;
      prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n-1; i>=0; --i){
      answer[i] *= suffix;
      suffix *= nums[i];
    }
    return answer;

  }
};


int main() {
  ProductExceptSelf P;

vector<int> input = {1,2,3,4};
vector<int> output = {24,12,8,6};
assert((P.productExceptSelf(input)) == output);

}
