#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class MaximumProfitJobScheduling {
public:
    int jobScheduling(vector<int> startTime, vector<int> endTime, vector<int> profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> jobs;
        for (int i = 0; i < n; ++i) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) starts[i] = get<0>(jobs[i]);
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            auto [s,e,p] = jobs[i];
            int next = lower_bound(starts.begin(), starts.end(), e) - starts.begin();
            dp[i] = max(dp[i + 1], p + dp[next]);
        }
        return dp[0];
    }
};
int main() {
    MaximumProfitJobScheduling s;
    assert(s.jobScheduling({1,2,3,3},{3,4,5,6},{50,10,40,70}) == 120);
    cout << "Passed\n";
    return 0;
}
