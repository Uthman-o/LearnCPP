#include <cassert>
#include <iostream>

using namespace std;

struct Rectangle {
    double left;
    double bottom;
    double right;
    double top;
};

class RectangleOverlap {
   public:
    bool overlaps(const Rectangle& a,
                  const Rectangle& b) {
        if (a.right <= b.left) return false;
        if (b.right <= a.left) return false;
        if (a.top <= b.bottom) return false;
        if (b.top <= a.bottom) return false;

        return true;
    }
};

int main() {
    RectangleOverlap s;

    assert(s.overlaps(
        {0,0,4,4},
        {2,2,6,6}));

    assert(!s.overlaps(
        {0,0,2,2},
        {2,0,4,2}));

    cout << "Passed\n";
    return 0;
}
