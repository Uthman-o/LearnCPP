#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<double> slidingWindowMax(const std::vector<double>& v, size_t k) {
    std::vector<double> out;

    if (k == 0 || v.empty()) return out;

    std::deque<size_t> dq;
    for (size_t i = 0; i < v.size(); ++i) {
        if (!dq.empty() && dq.front() + k <= i) dq.pop_front();
        while (!dq.empty() && v[dq.back()] <= v[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        if (i + 1 >= k) out.push_back(v[dq.front()]);
        /* code */
    }
    return out;
}

int main() {
    std::vector<double> v{1, 3, -1, -3, 5, 3, 6, 7};
    auto m = slidingWindowMax(v, 2);

    // std::vector<double> want{3, 3, 5, 5, 6, 7};
    std::vector<double> want{3, 3, -1, 5, 5, 6, 7};
    assert(m == want);

    return 0;
}
