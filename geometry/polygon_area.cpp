#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
};

class PolygonArea {
   public:
    double area(const vector<Point>& polygon) {
        double total = 0.0;
        int n = polygon.size();

        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;

            total += polygon[i].x * polygon[next].y;
            total -= polygon[i].y * polygon[next].x;
        }

        return fabs(total) / 2.0;
    }
};

int main() {
    PolygonArea s;

    vector<Point> rectangle = {
        {0, 0}, {4, 0}, {4, 3}, {0, 3}
    };

    assert(fabs(s.area(rectangle) - 12.0) < 1e-9);

    vector<Point> triangle = {
        {0, 0}, {4, 0}, {0, 3}
    };

    assert(fabs(s.area(triangle) - 6.0) < 1e-9);

    cout << "Passed\n";
    return 0;
}
