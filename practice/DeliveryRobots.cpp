#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class DeliveryRobots {
   private:
    long long maxOrdered(const vector<long long>& prefix, int n, int firstLength,
                         int secondLength) {
        long long bestFirst = LLONG_MIN;
        long long bestTotal = LLONG_MIN;

        for (int secondStart = firstLength; secondStart + secondLength <= n; ++secondStart) {
            int firstStart = secondStart - firstLength;
            long long firstSum = prefix[secondStart] - prefix[firstStart];

            bestFirst = max(bestFirst, firstSum);

            long long secondSum = prefix[secondStart + secondLength] - prefix[secondStart];

            bestTotal = max(bestTotal, bestFirst + secondSum);
        }
        return bestTotal;
    }

   public:
    long long maxDeliveryValue(const vector<int>& values, int c1, int c2) {
        int n = values.size();

        // assert(c1>0);
        // assert(c2 >0);
        // assert(c1+c2 <= n);

        if (c1 <= 0 || c2 <= 0 || c1 + c2 > n) return -1;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + values[i];
        }

        long long order1 = maxOrdered(prefix, n, c1, c2);
        long long order2 = maxOrdered(prefix, n, c2, c1);

        return max(order1, order2);
    }
};

int main() {
    DeliveryRobots D;

    {
        vector<int> values = {4, 2, 3, 5};
        cout << "Max Delivery Value is " << (D.maxDeliveryValue(values, 2, 1)) << endl;
    }

    {
        vector<int> values = {1, 2, 3, 4, 5};
        cout << "Max Delivery Value is " << (D.maxDeliveryValue(values, 2, 2)) << endl;
    }

    {
        vector<int> values = {5, 1, 1, 5};
        cout << "Max Delivery Value is " << (D.maxDeliveryValue(values, 1, 1)) << endl;
    }

    {
        vector<int> values = {1, 2, 3, 4};
        cout << "Max Delivery Value is " << (D.maxDeliveryValue(values, 2, 2)) << endl;
    }

    {
        vector<int> values = {1, 100, 1, 100, 1};
        cout << "Max Delivery Value is " << (D.maxDeliveryValue(values, 1, 1)) << endl;
    }
    return 0;
}
