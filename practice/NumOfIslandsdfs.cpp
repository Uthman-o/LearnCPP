#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
template <typename T>
using v = std::vector<T>;

class NumOfIslands {
   private:
    void dfs(v<v<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
            return;
        }

        // Mark Visited

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

   public:
    int numIslands(v<v<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++islands;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};

int main() {
    NumOfIslands N;

    v<v<char>> gridEmpty = {};
    v<v<char>> gridZero = {{'0', '0'}, {'0', '0'}};
    v<v<char>> gridOne = {{'1'}};
    v<v<char>> gridAll = {{'1', '1', '1'}, {'1', '1', '1'}, {'1', '1', '1'}};
    v<v<char>> gridIsolated = {{'1', '0', '1'}, {'0', '1', '0'}, {'1', '0', '1'}};
    v<v<char>> gridLongThin = {{'1', '1', '1', '1', '1'}};
    v<v<char>> gridDiffShape = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};

    assert(N.numIslands(gridEmpty) == 0);
    assert(N.numIslands(gridZero) == 0);
    assert(N.numIslands(gridOne) == 1);
    assert(N.numIslands(gridAll) == 1);
    assert(N.numIslands(gridIsolated) == 5);
    assert(N.numIslands(gridLongThin) == 1);
    assert(N.numIslands(gridDiffShape) == 3);

    return 0;
}
