#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
class WordDistance {
    unordered_map<string, vector<int>> positions;
public:
    WordDistance(const vector<string>& wordsDict) {
        for (int i = 0; i < (int)wordsDict.size(); ++i) positions[wordsDict[i]].push_back(i);
    }
    int shortest(const string& word1, const string& word2) {
        const auto& a = positions[word1];
        const auto& b = positions[word2];
        int i = 0, j = 0, best = INT_MAX;
        while (i < (int)a.size() && j < (int)b.size()) {
            best = min(best, abs(a[i] - b[j]));
            if (a[i] < b[j]) ++i;
            else ++j;
        }
        return best;
    }
};
int main() {
    vector<string> words = {"practice","makes","perfect","coding","makes"};
    WordDistance wd(words);
    assert(wd.shortest("coding","practice") == 3);
    assert(wd.shortest("makes","coding") == 1);
    cout << "Passed\n";
    return 0;
}
