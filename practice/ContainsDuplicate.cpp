#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

/***********************************************
Problem type: Hash set
Container: unordered_set
Time: O(n) average
Space: O(n)
******************************************************/

class ContainsDuplicate{
public:
  bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    if( nums.empty()) return false;

    for (int num: nums){
      if (seen.count(num)){
        return true;
      }
      seen.insert(num);
    }
    return false;
  }
};

int main(){
  ContainsDuplicate solver;

assert(solver.containsDuplicate({1,2,3,1}) == true);
assert(solver.containsDuplicate({1,2,3,4}) == false);
assert(solver.containsDuplicate({1,1}) == true);
assert(solver.containsDuplicate({}) == false);
assert(solver.containsDuplicate({5}) == false);

cout << "All tests passed\n";

  return 0;
}
