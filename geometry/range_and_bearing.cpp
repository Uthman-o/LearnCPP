#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Pose2D {
    double x;
    double y;
    double theta;
};

struct Measurement {
    double range;
    double bearing;
};

class RangeAndBearing {
   private:
    double wrapToPi(double angle) {
        const double PI = acos(-1.0);
        const double TWO_PI = 2.0 * PI;

        while (angle >= PI) angle -= TWO_PI;
        while (angle < -PI) angle += TWO_PI;

        return angle;
    }

   public:
    Measurement measure(const Pose2D& robot,
                        const Pose2D& target) {
        double dx = target.x - robot.x;
        double dy = target.y - robot.y;

        double range = sqrt(dx * dx + dy * dy);
        double globalBearing = atan2(dy, dx);

        double bearing =
            wrapToPi(globalBearing - robot.theta);

        return {range, bearing};
    }
};

int main() {
    RangeAndBearing s;

    const double PI = acos(-1.0);

    Pose2D robot{0,0,PI/2};
    Pose2D target{0,5,0};

    Measurement m = s.measure(robot, target);

    assert(fabs(m.range - 5.0) < 1e-9);
    assert(fabs(m.bearing) < 1e-9);

    cout << "Passed\n";
    return 0;
}
