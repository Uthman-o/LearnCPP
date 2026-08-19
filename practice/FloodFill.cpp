#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/************************************************
Problem type: Grid traversal / connected component
Container: queue<pair<int,int>> for BFS
Starting interview questions
  Is connectivity only up/down/left/right?
  Can I modify image directly?
  Are sr and sc guaranteed valid?
  Can the new color equal the starting color?

Complexity: O(R*C) time worst case, O(R*C) queue space worst case.
***************************************************/

using namespace std;

class FloodFill {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int oldColor = image[r][c];

        if (oldColor == color) return image;

        queue<pair<int, int>> q;
        q.push({r, c});

        image[r][c] = color;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nr = cr + d[0];
                int nc = cc + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == oldColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

int main() {
    FloodFill sol;

    // Normal case
    {
        vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

        vector<vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};

        assert(sol.floodFill(image, 1, 1, 2) == expected);
    }

    // New color equals old color
    {
        vector<vector<int>> image = {{1, 1}, {1, 0}};

        vector<vector<int>> expected = image;

        assert(sol.floodFill(image, 0, 0, 1) == expected);
    }

    // Single cell
    {
        vector<vector<int>> image = {{0}};
        vector<vector<int>> expected = {{5}};

        assert(sol.floodFill(image, 0, 0, 5) == expected);
    }

    // Diagonal does not connect
    {
        vector<vector<int>> image = {{1, 0}, {0, 1}};

        vector<vector<int>> expected = {{2, 0}, {0, 1}};

        assert(sol.floodFill(image, 0, 0, 2) == expected);
    }

    // Fill entire image
    {
        vector<vector<int>> image = {{3, 3}, {3, 3}};

        vector<vector<int>> expected = {{7, 7}, {7, 7}};

        assert(sol.floodFill(image, 0, 0, 7) == expected);
    }

    cout << "All tests passed\n";
    return 0;
}
