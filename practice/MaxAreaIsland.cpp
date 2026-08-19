#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/************************************************
Problem type: connected components in a 2D grid.

For every unvisited land cell (1), run BFS/DFS and count how many connected land cells belong to
that island. Keep the maximum count.

Interview questions to establish:

Are connections only up/down/left/right? Usually yes.
Can I modify the grid to mark visited cells?
Can the grid be empty?
What should I return if there is no land? 0.
***************************************************/

using namespace std;

class MaxAreaOfIsland {
   private:
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;  // visited

        int area = 0;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();

            area++;

            for (auto& d : directions) {
                int nr = cr + d[0];
                int nc = cc + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;  // mark as added
                    q.push({nr, nc});
                }
            }
        }
        return area;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int maxArea = 0;

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, bfs(grid, r, c));
                }
            }
        }
        return maxArea;
    }
};

int main() {
    MaxAreaOfIsland sol;

    // Empty grid
    {
        vector<vector<int>> grid = {};
        assert(sol.maxAreaOfIsland(grid) == 0);
    }

    // All water
    {
        vector<vector<int>> grid = {{0, 0}, {0, 0}};
        assert(sol.maxAreaOfIsland(grid) == 0);
    }

    // Single land cell
    {
        vector<vector<int>> grid = {{1}};
        assert(sol.maxAreaOfIsland(grid) == 1);
    }

    // Entire grid is one island
    {
        vector<vector<int>> grid = {{1, 1}, {1, 1}};
        assert(sol.maxAreaOfIsland(grid) == 4);
    }

    // Multiple islands
    {
        vector<vector<int>> grid = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 0, 1, 1}};

        // Left island = 3
        // Right island = 3
        assert(sol.maxAreaOfIsland(grid) == 3);
    }

    // Diagonal cells are NOT connected
    {
        vector<vector<int>> grid = {{1, 0}, {0, 1}};

        assert(sol.maxAreaOfIsland(grid) == 1);
    }

    // Long thin island
    {
        vector<vector<int>> grid = {{1, 1, 1, 1, 1}};

        assert(sol.maxAreaOfIsland(grid) == 5);
    }

    // Irregular shape
    {
        vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 1}};

        assert(sol.maxAreaOfIsland(grid) == 5);
    }

    cout << "All tests passed\n";

    return 0;
}
