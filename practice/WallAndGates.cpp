#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/************************************************
Problem type: Grid + multi-source BFS
Container: queue<pair<int,int>>

Key idea
  Put all gates into the queue first.

Interview questions
  Are movements only up/down/left/right?
  Are walls always -1, gates 0, and empty rooms INT_MAX?
  Should unreachable rooms remain INT_MAX?
  Can I modify the grid in place?

Complexity: O(R*C) time and O(R*C) worst-case queue space.
***************************************************/

using namespace std;

class WallsAndGates {
   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;

        int rows = rooms.size();
        int cols = rooms[0].size();

        queue<pair<int, int>> q;

        // Add ALL gates first
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && rooms[nr][nc] == INT_MAX) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};

int main() {
    WallsAndGates sol;
    const int INF = INT_MAX;

    // Standard case
    {
        vector<vector<int>> rooms = {
            {INF, -1, 0, INF}, {INF, INF, INF, -1}, {INF, -1, INF, -1}, {0, -1, INF, INF}};

        vector<vector<int>> expected = {
            {3, -1, 0, 1}, {2, 2, 1, -1}, {1, -1, 2, -1}, {0, -1, 3, 4}};

        sol.wallsAndGates(rooms);
        assert(rooms == expected);
    }

    // No gates
    {
        vector<vector<int>> rooms = {{INF, INF}, {INF, -1}};

        vector<vector<int>> expected = rooms;

        sol.wallsAndGates(rooms);
        assert(rooms == expected);
    }

    // All gates
    {
        vector<vector<int>> rooms = {{0, 0}, {0, 0}};

        vector<vector<int>> expected = rooms;

        sol.wallsAndGates(rooms);
        assert(rooms == expected);
    }

    // Unreachable room
    {
        vector<vector<int>> rooms = {{0, -1, INF}, {-1, -1, INF}};

        vector<vector<int>> expected = {{0, -1, INF}, {-1, -1, INF}};

        sol.wallsAndGates(rooms);
        assert(rooms == expected);
    }

    // Single gate
    {
        vector<vector<int>> rooms = {{0}};

        sol.wallsAndGates(rooms);

        assert(rooms[0][0] == 0);
    }

    cout << "All tests passed\n";
    return 0;
}
