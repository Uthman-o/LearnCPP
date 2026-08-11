#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class ShortestBinaryPath {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 0) return -1;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});

        // Mark visited

        grid[0][0] = 1;
        visited[0][0] = true;

        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        int pathLength = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1) return pathLength;

                for (auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 &&
                        !visited[nr][nc]) {
                        // grid[nr][nc] = 1;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            ++pathLength;
        }
        return -1;
    }
};

int main() {
    ShortestBinaryPath s;
    {
        std::vector<std::vector<int>> grid = {{0}};
        assert(s.shortestPathBinaryMatrix(grid) == 1);
    }

    {
        std::vector<std::vector<int>> grid = {{1}};
        assert(s.shortestPathBinaryMatrix(grid) == -1);
    }

    {
        std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};

        assert(s.shortestPathBinaryMatrix(grid) == 2);
    }

    return 0;
}
