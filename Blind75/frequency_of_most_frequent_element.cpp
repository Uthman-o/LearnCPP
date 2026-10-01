#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class FrequencyOfMostFrequentElement {
   public:
    int maxFrequency(vector<int> nums, long long k) {
        sort(nums.begin(), nums.end());

        long long windowSum = 0;
        int left = 0;
        int best = 1;

        for (int right = 0; right < nums.size(); ++right) {
            windowSum += nums[right];

            while (1LL * nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left];
                ++left;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};

int main() {
    FrequencyOfMostFrequentElement s;
    vector<int> nums = {1, 2, 4};
    assert(s.maxFrequency(nums, 5) == 3);
    cout << "Passed\n";
    return 0;
}
