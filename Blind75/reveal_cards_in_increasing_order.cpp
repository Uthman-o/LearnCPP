#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RevealCardsInIncreasingOrder {
   public:
    vector<int> deckRevealedIncreasing(vector<int> deck) {
        sort(deck.begin(), deck.end());

        queue<int> indices;
        for (int i = 0; i < deck.size(); ++i) indices.push(i);

        vector<int> ans(deck.size());

        for (int card : deck) {
            int index = indices.front();
            indices.pop();
            ans[index] = card;

            if (!indices.empty()) {
                indices.push(indices.front());
                indices.pop();
            }
        }

        return ans;
    }
};

int main() {
    RevealCardsInIncreasingOrder s;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> expected = {2, 13, 3, 11, 5, 17, 7};
    assert(s.deckRevealedIncreasing(deck) == expected);
    cout << "Passed\n";
    return 0;
}
