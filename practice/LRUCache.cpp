#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
   private:
    int capacity_;

    list<pair<int, int>> usage_;

    unordered_map<int, list<pair<int, int>>::iterator> cache_;

   public:
    explicit LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto mapIt = cache_.find(key);
        if (mapIt == cache_.end()) {
            return -1;
        }

        // Iterator to node in the list
        auto listIt = mapIt->second;

        // Move this node to front
        usage_.splice(usage_.begin(), usage_, listIt);

        return listIt->second;
    }

    void put(int key, int value) {
        auto mapIt = cache_.find(key);

        // Key already exixts
        if (mapIt != cache_.end()) {
            auto listIt = mapIt->second;
            listIt->second = value;

            // Mark as most recently used
            usage_.splice(usage_.begin(), usage_, listIt);
            return;
        }

        // Cache full
        if (usage_.size() == capacity_) {
            int lruKey = usage_.back().first;
            cache_.erase(lruKey);
            usage_.pop_back();
        }

        // Insert new item as most recently used.
        usage_.push_front({key, value});
        cache_[key] = usage_.begin();
    }

    void print() const {
        cout << "MRU ->";
        for (const auto& [key, value] : usage_) {
            cout << "[ " << key << ":" << value << " ]";
        }
        cout << "<- LRU\n";
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.print();
    cache.put(2, 20);
    cache.print();
    return 0;
}
