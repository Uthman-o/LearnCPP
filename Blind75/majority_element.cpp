#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class MajorityElement {
public:
    int majorityElement(const vector<int>& nums) {
        int candidate=0,count=0;
        for(int x:nums){
            if(count==0) candidate=x;
            count += (x==candidate) ? 1 : -1;
        }
        return candidate;
    }
};
int main(){
    MajorityElement s;
    assert(s.majorityElement({2,2,1,1,1,2,2})==2);
    cout<<"Passed\n";
    return 0;
}
