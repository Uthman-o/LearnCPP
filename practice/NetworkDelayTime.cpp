#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class NetworkDelay {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency[u] = {v, weight}
        vector<vector<pair<int, int>>> adjacency(n + 1);

        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjacency[u].push_back({v, w});
        }

        const int INF = INT_MAX;

        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        using State = pair<int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            // Ignore outdated heap entries

            if (currentDist > dist[u]) continue;

            for (auto [v, weight] : adjacency[u]) {
                int newDist = currentDist + weight;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        int answer = 0;
        for (int node = 1; node <= n; ++node) {
            if (dist[node] == INF) return -1;

            answer = max(answer, dist[node]);
        }
        return answer;
    }
};

int main() {
    NetworkDelay s;

    {
        std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

        assert(s.networkDelayTime(times, 4, 2) == 2);
    }

    {
        std::vector<std::vector<int>> times = {};
        assert(s.networkDelayTime(times, 1, 1) == 0);
    }

    {
        std::vector<std::vector<int>> times = {{1, 2, 5}};

        assert(s.networkDelayTime(times, 3, 1) == -1);
    }
}
