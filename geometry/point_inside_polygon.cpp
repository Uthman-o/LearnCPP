#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
};

class PointInsidePolygon {
   private:
    static constexpr double EPS = 1e-9;

    bool onSegment(const Point& p,
                   const Point& a,
                   const Point& b) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;

        double lengthSquared = dx * dx + dy * dy;

        if (lengthSquared == 0.0) {
            return fabs(p.x - a.x) < EPS &&
                   fabs(p.y - a.y) < EPS;
        }

        double t =
            ((p.x - a.x) * dx + (p.y - a.y) * dy) /
            lengthSquared;

        if (t < -EPS || t > 1.0 + EPS) {
            return false;
        }

        double closestX = a.x + t * dx;
        double closestY = a.y + t * dy;

        return fabs(p.x - closestX) < EPS &&
               fabs(p.y - closestY) < EPS;
    }

   public:
    bool contains(const vector<Point>& polygon,
                  const Point& p) {
        bool inside = false;
        int n = polygon.size();

        for (int i = 0, j = n - 1; i < n; j = i++) {
            const Point& a = polygon[j];
            const Point& b = polygon[i];

            if (onSegment(p, a, b)) {
                return true;
            }

            bool crossesY =
                (a.y > p.y) != (b.y > p.y);

            if (crossesY) {
                double xAtY =
                    a.x +
                    (p.y - a.y) *
                        (b.x - a.x) /
                        (b.y - a.y);

                if (p.x < xAtY) {
                    inside = !inside;
                }
            }
        }

        return inside;
    }
};

int main() {
    PointInsidePolygon s;

    vector<Point> square = {
        {0, 0}, {4, 0}, {4, 4}, {0, 4}
    };

    assert(s.contains(square, {2, 2}));
    assert(!s.contains(square, {5, 2}));
    assert(s.contains(square, {4, 2}));

    cout << "Passed\n";
    return 0;
}
