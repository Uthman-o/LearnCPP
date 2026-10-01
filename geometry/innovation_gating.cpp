#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

class InnovationGating {
   public:
    double nis(double residual,
               double innovationVariance) {
        return residual * residual /
               innovationVariance;
    }

    bool accept(double residual,
                double innovationVariance,
                double threshold) {
        return nis(
            residual,
            innovationVariance) <= threshold;
    }
};

int main() {
    InnovationGating s;

    double residual = 2.0;
    double S = 4.0;

    assert(fabs(s.nis(residual, S) - 1.0) < 1e-9);

    assert(s.accept(residual, S, 3.84));
    assert(!s.accept(5.0, 1.0, 3.84));

    cout << "Passed\n";
    return 0;
}
