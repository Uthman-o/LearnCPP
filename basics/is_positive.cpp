#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void know_your_algorithms() {
    const vector<int> data = {-1, -3, -5, 8, 15, -1};

    const auto is_positive = [](const auto &x) { return x > 0; };

    auto first_pos_it = find_if(data.cbegin(), data.cend(), is_positive);

    if (first_pos_it != data.cend()) {
        cout << "The first positive integer is at position " << (first_pos_it - data.cbegin())
             << endl;

        cout << "Value: " << *first_pos_it << endl;
    }
}

int main() {
    know_your_algorithms();

    return 0;
}
