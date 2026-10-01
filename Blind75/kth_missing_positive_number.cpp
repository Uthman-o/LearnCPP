#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class KthMissingPositiveNumber {
public:
    int findKthPositive(const vector<int>& arr, int k) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) left = mid + 1;
            else right = mid;
        }
        return left + k;
    }
};
int main() {
    KthMissingPositiveNumber s;
    assert(s.findKthPositive({2,3,4,7,11}, 5) == 9);
    cout << "Passed\n";
    return 0;
}
