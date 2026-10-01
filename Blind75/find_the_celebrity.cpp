#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class FindTheCelebrity {
   private:
    vector<vector<bool>> relation;

    bool knows(int a, int b) {
        return relation[a][b];
    }

   public:
    FindTheCelebrity(vector<vector<bool>> graph) : relation(graph) {}

    int findCelebrity(int n) {
        int candidate = 0;

        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) candidate = i;
        }

        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;

            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }

        return candidate;
    }
};

int main() {
    vector<vector<bool>> relation = {
        {false, true, true},
        {false, false, true},
        {false, false, false}
    };

    FindTheCelebrity s(relation);
    assert(s.findCelebrity(3) == 2);

    cout << "Passed\n";
    return 0;
}
