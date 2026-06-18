// AeroVect-style STL patterns: analyzing a stream of fleet events.
// Compile: g++ -std=c++17 -Wall -Wextra fleet_stats.cpp -o stats && ./stats
//
// Patterns covered (the ones that show up live):
//   1. group-by-key:        map<key, vector<T>>
//   2. frequency count:     ++m[key]
//   3. accumulate per key
//   4. find the max by a derived value (max_element + lambda)
//   5. sort with a custom comparator (lambda)
//   6. priority_queue with a custom comparator (min-heap)
//   7. structured bindings + range-for over a map
//   8. operator[] vs .at() vs .find()  (the inserting gotcha)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

struct Event {
    int vehicleId;
    std::string type;  // "dispatch", "arrive", "charge"
    double x, y;       // position when the event fired
};

int mostDispatches(const std::vector<Event>& log) {
    std::map<int, int> counts;
    for (const auto& e : log) {
        if (e.type == "dispatch") ++counts[e.vehicleId];
    }

    int bestId = -1;
    int bestCount = 0;

    for (const auto& [id, c] : counts) {
        if (c > bestCount) {
            bestCount = c;
            bestId = id;
        }
    }

    if(bestId == -1){
      bestId = 0;
    }

    return bestId;
}

int main() {
    // Pretend this came off a log file / message bus.
    std::vector<Event> log = {
        {1, "dispatch", 0, 0}, {1, "arrive", 3, 4}, {1, "dispatch", 3, 4}, {2, "dispatch", 0, 0},
        {2, "arrive", 0, 5},   {1, "arrive", 6, 8}, {2, "charge", 0, 5},   {3, "dispatch", 1, 1},
    };

    // --- 1. group-by-key: build per-vehicle history ---------------------
    // map keeps keys sorted (handy for ordered output). Use unordered_map
    // if you only need lookups and want average O(1) instead of O(log n).
    std::map<int, std::vector<Event>> byVehicle;
    for (const auto& e : log) {
        byVehicle[e.vehicleId].push_back(e);  // operator[] default-constructs
    }                                         // the vector on first touch

    // --- 2. frequency count of event types ------------------------------
    std::map<std::string, int> typeCounts;
    for (const auto& e : log) ++typeCounts[e.type];  // int value-inits to 0

    std::cout << "Event counts:\n";
    for (const auto& [type, n] : typeCounts) {  // 7. structured bindings
        std::cout << "  " << type << ": " << n << "\n";
    }

    // --- 3. accumulate: total distance traveled per vehicle -------------
    std::unordered_map<int, double> distanceByVehicle;
    for (const auto& [id, events] : byVehicle) {
        double total = 0.0;
        for (std::size_t i = 1; i < events.size(); ++i) {
            total += std::hypot(events[i].x - events[i - 1].x, events[i].y - events[i - 1].y);
        }
        distanceByVehicle[id] = total;
    }

    std::cout << "\nDistance per vehicle:\n";
    for (const auto& [id, d] : byVehicle) {
        std::cout << "  #" << id << ": " << distanceByVehicle[id] << "\n";
        (void)d;
    }

    // --- 4. find the busiest vehicle (max by a derived value) -----------
    auto busiest =
        std::max_element(distanceByVehicle.begin(), distanceByVehicle.end(),
                         [](const auto& a, const auto& b) { return a.second < b.second; });
    if (busiest != distanceByVehicle.end()) {
        std::cout << "\nBusiest: #" << busiest->first << " (" << busiest->second << ")\n";
    }

    // --- 5. sort vehicle ids by distance, descending --------------------
    std::vector<int> ids;
    for (const auto& [id, d] : distanceByVehicle) {
        ids.push_back(id);
        (void)d;
    }
    std::sort(ids.begin(), ids.end(), [&](int a, int b) {
        return distanceByVehicle[a] > distanceByVehicle[b];  // custom comparator
    });
    std::cout << "Ranked by distance:";
    for (int id : ids) std::cout << " #" << id;
    std::cout << "\n";

    // --- 6. priority_queue: dispatch pending jobs nearest-first ---------
    // priority_queue is a MAX-heap by default. For "smallest distance first"
    // you invert the comparator (greater<>) -> a min-heap.
    {
        using Job = std::pair<double, int>;  // {distanceToDepot, jobId}
        std::priority_queue<Job, std::vector<Job>, std::greater<Job>> pq;
        pq.push({4.2, 101});
        pq.push({1.0, 102});
        pq.push({2.5, 103});
        std::cout << "Job order (nearest first):";
        while (!pq.empty()) {
            std::cout << " " << pq.top().second;
            pq.pop();
        }
        std::cout << "\n";
    }

    // --- 8. operator[] vs .at() vs .find() ------------------------------
    // operator[] INSERTS a default value if the key is missing -> using it to
    // "check" a key silently grows the map. Use .find() or .count()/.contains()
    // to look without inserting, and .at() to read with bounds checking.
    std::map<int, double> m = {{1, 9.0}};
    if (auto it = m.find(2); it == m.end()) {
        std::cout << "key 2 absent (and find did NOT insert it)\n";
    }
    // m.at(2);  // would THROW std::out_of_range, not insert.\\

    std::cout << "Most dispatches: #" << mostDispatches(log) << "\n";  // #1 (2x)

    std::vector<Event> tie = {
        {5, "dispatch", 0, 0}, {2, "dispatch", 0, 0},  // both 1 -> smaller id 2
    };
    std::cout << "Tie case: #" << mostDispatches(tie) << "\n";  // #2

    std::cout << "Empty case: #" << mostDispatches({}) << "\n";  // #-1

    return 0;
}
