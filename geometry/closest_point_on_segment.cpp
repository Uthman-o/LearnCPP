#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class ClosestPointOnSegment {
   public:
    Point closestPoint(const Point& p,
                       const Point& a,
                       const Point& b) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;

        double lengthSquared = dx * dx + dy * dy;

        if (lengthSquared == 0.0) {
            return a;
        }

        double t =
            ((p.x - a.x) * dx +
             (p.y - a.y) * dy) /
            lengthSquared;

        t = max(0.0, min(1.0, t));

        return {
            a.x + t * dx,
            a.y + t * dy
        };
    }
};

int main() {
    ClosestPointOnSegment s;

    Point q = s.closestPoint(
        {2, 3}, {0, 0}, {4, 0});

    assert(fabs(q.x - 2.0) < 1e-9);
    assert(fabs(q.y - 0.0) < 1e-9);

    Point q2 = s.closestPoint(
        {6, 1}, {0, 0}, {4, 0});

    assert(fabs(q2.x - 4.0) < 1e-9);

    cout << "Passed\n";
    return 0;
}
