#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class ConnectedComponents {
   private:
    void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            cout << "Visiting city: " << city << endl;

            for (int neighbour : graph[city]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

   public:
    int countComponents(int numCities, const vector<vector<int>>& roads) {
        // Adjacency list
        vector<vector<int>> graph(numCities);

        for (const auto& road : roads) {
            assert(road.size() == 2);

            int city1 = road[0];
            int city2 = road[1];

            assert(city1 >= 0 && city1 < numCities);
            assert(city2 >= 0 && city2 < numCities);

            graph[city1].push_back(city2);
            graph[city2].push_back(city1);
        }

        // Print graph
        cout << "\nRoad Network:\n";
        for (int city = 0; city < numCities; ++city) {
            cout << city << " -> ";
            for (int neighbour : graph[city]) {
                cout << neighbour << " ";
            }

            cout << endl;
        }

        vector<bool> visited(numCities, false);

        int components = 0;

        // check every city1
        for (int city = 0; city < numCities; ++city) {
            if (!visited[city]) {
                components++;

                cout << "\nStarting component " << components << " from city " << city << endl;

                bfs(city, graph, visited);
            }
        }
        return components;
    }
};

int main() {
    ConnectedComponents C;

    {
        int numCities = 5;
        vector<vector<int>> roads{{0, 1}, {1, 2}, {3, 4}};

        int result = C.countComponents(numCities, roads);
        cout << "\nNumber of connected components: " << result << endl;
        assert(result == 2);
    }

    {
        int numCities = 4;
        vector<vector<int>> roads{{0, 1}, {1, 2}, {2, 3}};

        int result = C.countComponents(numCities, roads);
        cout << "\nNumber of connected components: " << result << endl;
        assert(result == 1);
    }

    return 0;
}
