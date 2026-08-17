#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RottingOranges {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Find initial rotten oranges and count fresh oranges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    ++fresh;
            }
        }

        // No fresh oranges
        if (fresh == 0) return 0;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int levelSize = q.size();
            // cout << levelSize << endl;

            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        --fresh;

                        q.push({nr, nc});
                    }
                }
            }

            ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    RottingOranges s;
    vector<vector<int>> grid = {{0, 2}};
    assert(s.orangesRotting(grid) == 0);

    vector<vector<int>> gridOne = {{1}};
    assert(s.orangesRotting(gridOne) == -1);

    vector<vector<int>> gridIsolated = {{2, 0, 1}};
    assert(s.orangesRotting(gridOne) == -1);

    vector<vector<int>> gridMulti = {{2, 1}, {1, 2}};
    assert(s.orangesRotting(gridMulti) == 1);

    vector<vector<int>> gridSample = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int m = s.orangesRotting(gridSample);

    cout << m << " minutes" << endl;
    return 0;
}
