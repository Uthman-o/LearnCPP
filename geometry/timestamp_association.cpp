#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class TimestampAssociation {
   public:
    int nearestIndex(const vector<double>& timestamps,
                     double query) {
        int bestIndex = 0;
        double bestError =
            fabs(timestamps[0] - query);

        for (int i = 1;
             i < timestamps.size();
             ++i) {
            double error =
                fabs(timestamps[i] - query);

            if (error < bestError) {
                bestError = error;
                bestIndex = i;
            }
        }

        return bestIndex;
    }
};

int main() {
    TimestampAssociation s;

    vector<double> times =
        {0.0, 0.1, 0.2, 0.3, 0.4};

    assert(s.nearestIndex(times, 0.26) == 3);
    assert(s.nearestIndex(times, 0.02) == 0);

    cout << "Passed\n";
    return 0;
}
