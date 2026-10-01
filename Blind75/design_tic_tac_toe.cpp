#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class TicTacToe {
    vector<int> rows, cols;
    int diag = 0, antiDiag = 0, n;
public:
    TicTacToe(int size) : rows(size,0), cols(size,0), n(size) {}
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        if (row == col) diag += add;
        if (row + col == n - 1) antiDiag += add;
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(antiDiag) == n)
            return player;
        return 0;
    }
};
int main() {
    TicTacToe game(3);
    assert(game.move(0,0,1) == 0);
    assert(game.move(0,2,2) == 0);
    assert(game.move(1,1,1) == 0);
    assert(game.move(0,1,2) == 0);
    assert(game.move(2,2,1) == 1);
    cout << "Passed\n";
    return 0;
}
