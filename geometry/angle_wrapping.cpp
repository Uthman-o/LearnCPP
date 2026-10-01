#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

class AngleWrapping {
   public:
    double wrapToPi(double angle) {
        const double PI = acos(-1.0);
        const double TWO_PI = 2.0 * PI;

        while (angle >= PI) {
            angle -= TWO_PI;
        }

        while (angle < -PI) {
            angle += TWO_PI;
        }

        return angle;
    }

    double angleDifference(double target,
                           double current) {
        return wrapToPi(target - current);
    }
};

int main() {
    AngleWrapping s;

    const double PI = acos(-1.0);

    assert(fabs(s.wrapToPi(3.0 * PI) + PI)
           < 1e-9);

    double difference =
        s.angleDifference(
            -170.0 * PI / 180.0,
             170.0 * PI / 180.0);

    assert(fabs(
               difference -
               20.0 * PI / 180.0) <
           1e-9);

    cout << "Passed\n";
    return 0;
}
