#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
};

class CircleLineIntersection {
   public:
    vector<Point> intersect(const Point& a,
                            const Point& b,
                            const Point& center,
                            double radius) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;

        double x = a.x - center.x;
        double y = a.y - center.y;

        // Substitute the line
        // a + t(b-a)
        // into the circle equation.
        double A = dx * dx + dy * dy;
        double B = 2.0 * (x * dx + y * dy);
        double C = x * x + y * y -
                   radius * radius;

        double discriminant =
            B * B - 4.0 * A * C;

        if (discriminant < 0.0) {
            return {};
        }

        if (fabs(discriminant) < 1e-9) {
            double t = -B / (2.0 * A);

            return {{
                a.x + t * dx,
                a.y + t * dy
            }};
        }

        double root = sqrt(discriminant);

        double t1 = (-B - root) / (2.0 * A);
        double t2 = (-B + root) / (2.0 * A);

        return {
            {a.x + t1 * dx, a.y + t1 * dy},
            {a.x + t2 * dx, a.y + t2 * dy}
        };
    }
};

int main() {
    CircleLineIntersection s;

    auto points = s.intersect(
        {-2, 0}, {2, 0}, {0, 0}, 1.0);

    assert(points.size() == 2);
    assert(fabs(points[0].x + 1.0) < 1e-9);
    assert(fabs(points[1].x - 1.0) < 1e-9);

    auto none = s.intersect(
        {-2, 2}, {2, 2}, {0, 0}, 1.0);

    assert(none.empty());

    cout << "Passed\n";
    return 0;
}
