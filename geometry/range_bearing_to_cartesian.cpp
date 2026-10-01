#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class RangeBearingToCartesian {
   public:
    Point convert(double range,
                  double bearing) {
        return {
            range * cos(bearing),
            range * sin(bearing)
        };
    }
};

int main() {
    RangeBearingToCartesian s;

    const double PI = acos(-1.0);

    Point p = s.convert(2.0, PI / 2.0);

    assert(fabs(p.x) < 1e-9);
    assert(fabs(p.y - 2.0) < 1e-9);

    cout << "Passed\n";
    return 0;
}
