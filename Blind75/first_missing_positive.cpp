#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int> nums) {
        int n=nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;++i) if(nums[i]!=i+1) return i+1;
        return n+1;
    }
};
int main(){
    FirstMissingPositive s;
    assert(s.firstMissingPositive({3,4,-1,1})==2);
    assert(s.firstMissingPositive({1,2,0})==3);
    cout<<"Passed\n";
    return 0;
}
