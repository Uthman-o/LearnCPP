#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class GroupAnagrams {
   public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            array<int, 26> count{};

            for (char c : word) {
                count[c - 'a']++;
            }

            string key;
            for (int x : count) {
                key += "#" + to_string(x);
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto& [key, group] : groups) {
            ans.push_back(group);
        }

        return ans;
    }
};

int main() {
    GroupAnagrams s;
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups = s.groupAnagrams(words);

    assert(groups.size() == 3);
    cout << "Passed\n";
    return 0;
}
