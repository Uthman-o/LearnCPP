#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point2D {
    double x;
    double y;
};

struct Pose2D {
    double x;
    double y;
    double theta;
};

class CoordinateTransforms {
   public:
    Point2D localToWorld(const Point2D& local,
                         const Pose2D& pose) {
        double c = cos(pose.theta);
        double s = sin(pose.theta);

        double worldX =
            pose.x +
            c * local.x -
            s * local.y;

        double worldY =
            pose.y +
            s * local.x +
            c * local.y;

        return {worldX, worldY};
    }

    Point2D worldToLocal(const Point2D& world,
                         const Pose2D& pose) {
        double dx = world.x - pose.x;
        double dy = world.y - pose.y;

        double c = cos(pose.theta);
        double s = sin(pose.theta);

        double localX =
            c * dx + s * dy;

        double localY =
            -s * dx + c * dy;

        return {localX, localY};
    }
};

int main() {
    CoordinateTransforms s;

    const double PI = acos(-1.0);

    Pose2D robot{10.0, 5.0, PI / 2.0};

    Point2D world =
        s.localToWorld({2.0, 0.0}, robot);

    assert(fabs(world.x - 10.0) < 1e-9);
    assert(fabs(world.y - 7.0) < 1e-9);

    Point2D local =
        s.worldToLocal(world, robot);

    assert(fabs(local.x - 2.0) < 1e-9);
    assert(fabs(local.y) < 1e-9);

    cout << "Passed\n";
    return 0;
}
