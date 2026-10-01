#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Estimate1D {
    double x;
    double P;
};

class KalmanFilter1D {
   public:
    Estimate1D predict(const Estimate1D& est,
                       double Q) {
        return {
            est.x,
            est.P + Q
        };
    }

    Estimate1D update(const Estimate1D& pred,
                      double z,
                      double R) {
        double K =
            pred.P / (pred.P + R);

        double x =
            pred.x +
            K * (z - pred.x);

        double P =
            (1.0 - K) * pred.P;

        return {x, P};
    }
};

int main() {
    KalmanFilter1D kf;

    Estimate1D est{0.0, 1.0};

    Estimate1D pred =
        kf.predict(est, 0.1);

    Estimate1D updated =
        kf.update(pred, 1.0, 0.5);

    assert(updated.x > 0.0);
    assert(updated.x < 1.0);
    assert(updated.P < pred.P);

    cout << "Passed\n";
    return 0;
}
