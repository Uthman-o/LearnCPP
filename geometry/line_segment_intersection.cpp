#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class LineSegmentIntersection {
   private:
    static constexpr double EPS = 1e-9;

    bool pointOnSegment(const Point& p, const Point& a, const Point& b) {
        // Line equation: A*x + B*y + C = 0
        double A = b.y - a.y;
        double B = a.x - b.x;
        double C = -(A * a.x + B * a.y);

        if (fabs(A * p.x + B * p.y + C) > EPS) {
            return false;
        }

        return p.x >= min(a.x, b.x) - EPS &&
               p.x <= max(a.x, b.x) + EPS &&
               p.y >= min(a.y, b.y) - EPS &&
               p.y <= max(a.y, b.y) + EPS;
    }

   public:
    bool intersects(const Point& a, const Point& b,
                    const Point& c, const Point& d) {
        double rX = b.x - a.x;
        double rY = b.y - a.y;
        double sX = d.x - c.x;
        double sY = d.y - c.y;

        double denominator = rX * sY - rY * sX;

        // Parallel lines.
        if (fabs(denominator) < EPS) {
            return pointOnSegment(a, c, d) ||
                   pointOnSegment(b, c, d) ||
                   pointOnSegment(c, a, b) ||
                   pointOnSegment(d, a, b);
        }

        // Solve:
        // a + t(b-a) = c + u(d-c)
        double dx = c.x - a.x;
        double dy = c.y - a.y;

        double t = (dx * sY - dy * sX) / denominator;
        double u = (dx * rY - dy * rX) / denominator;

        return t >= -EPS && t <= 1.0 + EPS &&
               u >= -EPS && u <= 1.0 + EPS;
    }
};

int main() {
    LineSegmentIntersection s;

    assert(s.intersects({0, 0}, {4, 4},
                        {0, 4}, {4, 0}));

    assert(!s.intersects({0, 0}, {1, 1},
                         {2, 2}, {3, 3}));

    assert(s.intersects({0, 0}, {2, 0},
                        {2, 0}, {4, 0}));

    cout << "Passed\n";
    return 0;
}
