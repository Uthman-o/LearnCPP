#include <cassert>
#include <cmath>
#include <iostream>
#include <optional>

struct Point {
    double x;
    double y;
};

constexpr double EPS = 1e-9;

std::optional<Point> findLaneConnection(const Point &A, const Point &B, const Point &C,
                                        const Point &D) {
    double rx = B.x - A.x;
    double ry = B.y - A.y;

    double sx = D.x - C.x;
    double sy = D.y - C.y;

    double dx = C.x - A.x;
    double dy = C.y - A.y;

    // Solve
    //  rx*t -sx*u = dx
    // ry*t - sy*u = dy

    double denom = sx * ry - rx * sy;

    if (std::abs(denom) < EPS) return std::nullopt;

    double t = (sx * dy - dx * sy) / denom;
    double u = (rx * dy - dx * ry) / denom;

    // INtersection must lie on both segments.

    if (t < -EPS || t > 1.0 + EPS || u < -EPS || u > 1.0 + EPS) return std::nullopt;

    Point intersection{A.x + t + rx, A.y + t + ry};

    return intersection;
}

int main() {
    // Crossing
    {
        // Point A{0, 0}, B{4, 4};
        // Point C{0, 4}, D{4, 0};
        Point A{0, 0}, B{4, 0};
        Point C{0, 1}, D{4, 1};

        auto p = findLaneConnection(A, B, C, D);
        std::cout << p->x << " " << p->y << std::endl;

        assert(p.has_value());
    }
    return 0;
}
