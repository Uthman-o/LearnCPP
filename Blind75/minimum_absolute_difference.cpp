#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class MinimumAbsoluteDifference {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> arr) {
        sort(arr.begin(), arr.end());
        int best=INT_MAX;
        vector<vector<int>> ans;
        for (int i=1;i<(int)arr.size();++i) best=min(best,arr[i]-arr[i-1]);
        for (int i=1;i<(int)arr.size();++i)
            if (arr[i]-arr[i-1]==best) ans.push_back({arr[i-1],arr[i]});
        return ans;
    }
};
int main() {
    MinimumAbsoluteDifference s;
    vector<vector<int>> expected={{1,2},{2,3},{3,4}};
    assert(s.minimumAbsDifference({4,2,1,3})==expected);
    cout << "Passed\n";
    return 0;
}
