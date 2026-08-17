#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class MergeIntervals {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = result.back();
            vector<int>& current = intervals[i];

            if (current[0] <= last[1]) {
                last[1] = max(last[1], current[1]);
            } else {
                result.push_back(current);
            }
        }
        return result;
    }
};

int main() {
    MergeIntervals M;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
    assert(M.merge(intervals) == expected);
    return 0;
}
