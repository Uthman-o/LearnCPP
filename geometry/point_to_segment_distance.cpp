#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class PointToSegmentDistance {
   public:
    double distanceToSegment(const Point& p,
                             const Point& a,
                             const Point& b) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;

        double lengthSquared = dx * dx + dy * dy;

        if (lengthSquared == 0.0) {
            double px = p.x - a.x;
            double py = p.y - a.y;
            return sqrt(px * px + py * py);
        }

        double t =
            ((p.x - a.x) * dx + (p.y - a.y) * dy) /
            lengthSquared;

        t = max(0.0, min(1.0, t));

        double closestX = a.x + t * dx;
        double closestY = a.y + t * dy;

        double ex = p.x - closestX;
        double ey = p.y - closestY;

        return sqrt(ex * ex + ey * ey);
    }
};

int main() {
    PointToSegmentDistance s;

    assert(fabs(s.distanceToSegment(
                    {2, 3}, {0, 0}, {4, 0}) -
                3.0) <
           1e-9);

    assert(fabs(s.distanceToSegment(
                    {6, 0}, {0, 0}, {4, 0}) -
                2.0) <
           1e-9);

    cout << "Passed\n";
    return 0;
}
