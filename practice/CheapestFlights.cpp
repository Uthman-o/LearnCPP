#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

/*********************************************
Problem type: Shortest path with a constraint on number of edges
Best simple approach: Bellman-Ford limited to k + 1 flights
Container: vector<int> dist

***********************************************/

using namespace std;

class CheapestFlights {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist;

            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if (dist[from] == INT_MAX) continue;

                temp[to] = min(temp[to], dist[from] + cost);
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    CheapestFlights sol;

    // Normal case: cheaper route uses one stop
    {
        int n = 4;

        vector<vector<int>> flights = {
            {0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}, {0, 3, 700}};

        // At most 2 flights.
        // 0 -> 2 -> 3 = 600
        assert(sol.findCheapestPrice(n, flights, 0, 3, 1) == 600);
    }

    // No stops allowed: direct flight only
    {
        int n = 3;

        vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};

        assert(sol.findCheapestPrice(n, flights, 0, 2, 0) == 500);
    }

    // One stop allows cheaper route
    {
        int n = 3;

        vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};

        assert(sol.findCheapestPrice(n, flights, 0, 2, 1) == 200);
    }

    // Destination unreachable
    {
        int n = 4;

        vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}};

        assert(sol.findCheapestPrice(n, flights, 0, 3, 2) == -1);
    }

    // Cheapest path requires too many stops
    {
        int n = 4;

        vector<vector<int>> flights = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {0, 3, 100}};

        // k = 1 means max 2 flights.
        // 0->1->2->3 is not allowed.
        assert(sol.findCheapestPrice(n, flights, 0, 3, 1) == 100);
    }

    // Source equals destination
    {
        int n = 2;

        vector<vector<int>> flights = {{0, 1, 100}};

        assert(sol.findCheapestPrice(n, flights, 0, 0, 0) == 0);
    }

    cout << "All tests passed\n";
    return 0;
}
