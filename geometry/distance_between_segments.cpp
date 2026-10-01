#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class DistanceBetweenSegments {
   private:
    static constexpr double EPS = 1e-9;

    double pointToSegment(const Point& p,
                          const Point& a,
                          const Point& b) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;
        double len2 = dx * dx + dy * dy;

        if (len2 == 0.0) {
            double ex = p.x - a.x;
            double ey = p.y - a.y;
            return sqrt(ex * ex + ey * ey);
        }

        double t =
            ((p.x - a.x) * dx +
             (p.y - a.y) * dy) / len2;

        t = max(0.0, min(1.0, t));

        double qx = a.x + t * dx;
        double qy = a.y + t * dy;

        double ex = p.x - qx;
        double ey = p.y - qy;

        return sqrt(ex * ex + ey * ey);
    }

    bool intersects(const Point& a,
                    const Point& b,
                    const Point& c,
                    const Point& d) {
        double rX = b.x - a.x;
        double rY = b.y - a.y;
        double sX = d.x - c.x;
        double sY = d.y - c.y;

        double denom = rX * sY - rY * sX;

        if (fabs(denom) < EPS) {
            return false;
        }

        double dx = c.x - a.x;
        double dy = c.y - a.y;

        double t = (dx * sY - dy * sX) / denom;
        double u = (dx * rY - dy * rX) / denom;

        return t >= 0.0 && t <= 1.0 &&
               u >= 0.0 && u <= 1.0;
    }

   public:
    double distance(const Point& a,
                    const Point& b,
                    const Point& c,
                    const Point& d) {
        if (intersects(a, b, c, d)) {
            return 0.0;
        }

        return min({
            pointToSegment(a, c, d),
            pointToSegment(b, c, d),
            pointToSegment(c, a, b),
            pointToSegment(d, a, b)
        });
    }
};

int main() {
    DistanceBetweenSegments s;

    assert(fabs(
        s.distance({0,0},{4,0},
                   {2,2},{2,5}) - 2.0) < 1e-9);

    assert(fabs(
        s.distance({0,0},{4,4},
                   {0,4},{4,0})) < 1e-9);

    cout << "Passed\n";
    return 0;
}
