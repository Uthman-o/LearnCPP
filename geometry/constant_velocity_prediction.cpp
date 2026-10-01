#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct State {
    double x;
    double y;
    double vx;
    double vy;
};

class ConstantVelocityPrediction {
   public:
    State predict(const State& state,
                  double dt) {
        State next = state;

        next.x += state.vx * dt;
        next.y += state.vy * dt;

        return next;
    }
};

int main() {
    ConstantVelocityPrediction s;

    State x{1,2,3,-1};

    State next = s.predict(x, 2.0);

    assert(fabs(next.x - 7.0) < 1e-9);
    assert(fabs(next.y - 0.0) < 1e-9);
    assert(fabs(next.vx - 3.0) < 1e-9);

    cout << "Passed\n";
    return 0;
}
