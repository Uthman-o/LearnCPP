#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaximumMatrixSum {
   public:
    long long maxMatrixSum(const vector<vector<int>>& matrix) {
        long long sum = 0;
        int negatives = 0;
        int minAbs = INT_MAX;

        for (const auto& row : matrix) {
            for (int x : row) {
                if (x < 0) ++negatives;
                sum += llabs((long long)x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negatives % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};

int main() {
    MaximumMatrixSum s;
    vector<vector<int>> matrix = {{1, -1}, {-1, 1}};
    assert(s.maxMatrixSum(matrix) == 4);
    cout << "Passed\n";
    return 0;
}
