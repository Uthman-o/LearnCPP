#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RankTeamsByVotes {
   public:
    string rankTeams(const vector<string>& votes) {
        int positions = votes[0].size();
        array<array<int, 26>, 26> count{};

        for (const string& vote : votes) {
            for (int i = 0; i < vote.size(); ++i) {
                count[vote[i] - 'A'][i]++;
            }
        }

        string teams = votes[0];

        sort(teams.begin(), teams.end(), [&](char a, char b) {
            for (int pos = 0; pos < positions; ++pos) {
                int ca = count[a - 'A'][pos];
                int cb = count[b - 'A'][pos];

                if (ca != cb) return ca > cb;
            }

            return a < b;
        });

        return teams;
    }
};

int main() {
    RankTeamsByVotes s;
    vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    assert(s.rankTeams(votes) == "ACB");
    cout << "Passed\n";
    return 0;
}
