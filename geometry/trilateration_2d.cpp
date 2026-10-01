#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

class Trilateration2D {
   public:
    Point solve(const Point& a, double r1,
                const Point& b, double r2,
                const Point& c, double r3) {
        double A1 = 2.0 * (b.x - a.x);
        double B1 = 2.0 * (b.y - a.y);

        double C1 =
            r1 * r1 - r2 * r2
            - a.x * a.x + b.x * b.x
            - a.y * a.y + b.y * b.y;

        double A2 = 2.0 * (c.x - a.x);
        double B2 = 2.0 * (c.y - a.y);

        double C2 =
            r1 * r1 - r3 * r3
            - a.x * a.x + c.x * c.x
            - a.y * a.y + c.y * c.y;

        double determinant =
            A1 * B2 - A2 * B1;

        assert(fabs(determinant) > 1e-9);

        double x =
            (C1 * B2 - C2 * B1) /
            determinant;

        double y =
            (A1 * C2 - A2 * C1) /
            determinant;

        return {x, y};
    }
};

int main() {
    Trilateration2D s;

    Point truth{2,3};

    Point a{0,0};
    Point b{6,0};
    Point c{0,8};

    double r1 =  sqrt(13.0);
    double r2 = 5.0;
    double r3 = sqrt(29.0);

    Point estimate =
        s.solve(a,r1,b,r2,c,r3);

    assert(fabs(estimate.x - truth.x) < 1e-9);
    assert(fabs(estimate.y - truth.y) < 1e-9);

    cout << "Passed\n";
    return 0;
}
