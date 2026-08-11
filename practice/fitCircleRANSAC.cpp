#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

struct Point {
    double x;
    double y;
};

struct Circle {
    double cx;
    double cy;
    double r;
    int inliers;
};

bool fitCircleFrom3Points(const Point& p1, const Point& p2, const Point& p3, Circle& circle) {
    double a = p2.x - p1.x;
    double b = p2.y - p1.y;
    double c = p3.x - p1.x;
    double d = p3.y - p1.y;

    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);

    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);

    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));

    if (std::abs(g) < 1e-9) {
        return false;  // points are collinear
    }

    circle.cx = (d * e - b * f) / g;
    circle.cy = (a * f - c * e) / g;
    circle.r = std::hypot(p1.x - circle.cx, p1.y - circle.cy);
    circle.inliers = 0;

    return true;
}

std::vector<Point> sampleThreePoints(const std::vector<Point>& points, std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, points.size() - 1);

    int i = dist(rng);
    int j = dist(rng);
    int k = dist(rng);

    while (j == i) j = dist(rng);

    while (k == i || k == j) k = dist(rng);

    return {points[i], points[j], points[k]};
}

int countInliers(const std::vector<Point>& points, const Circle& circle, double threshold) {
    int count = 0;

    for (const auto& p : points) {
        double distanceToCenter = std::hypot(p.x - circle.cx, p.y - circle.cy);

        double error = std::abs(distanceToCenter - circle.r);

        if (error < threshold) {
            ++count;
        }
    }

    return count;
}

Circle fitCircleRANSAC(const std::vector<Point>& points, int iterations, double threshold) {
    Circle bestCircle{0.0, 0.0, 0.0, 0};

    if (points.size() < 3) {
        return bestCircle;
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    for (int iter = 0; iter < iterations; ++iter) {
        std::vector<Point> sample = sampleThreePoints(points, rng);

        Circle candidate;

        bool success = fitCircleFrom3Points(sample[0], sample[1], sample[2], candidate);

        if (!success) {
            continue;
        }

        candidate.inliers = countInliers(points, candidate, threshold);

        if (candidate.inliers > bestCircle.inliers) {
            bestCircle = candidate;
        }
    }

    return bestCircle;
}

int main() {
    std::vector<Point> points;

    // Circle centered at (2, 3), radius 5
    points.push_back({7.0, 3.0});
    points.push_back({2.0, 8.0});
    points.push_back({-3.0, 3.0});
    points.push_back({2.0, -2.0});
    points.push_back({5.535, 6.535});
    points.push_back({-1.535, 6.535});

    // Outliers
    points.push_back({20.0, 20.0});
    points.push_back({-10.0, 15.0});
    points.push_back({12.0, -8.0});

    int iterations = 1000;
    double threshold = 0.2;

    Circle result = fitCircleRANSAC(points, iterations, threshold);

    std::cout << "Best circle:\n";
    std::cout << "Center: (" << result.cx << ", " << result.cy << ")\n";

    std::cout << "Radius: " << result.r << "\n";

    std::cout << "Inliers: " << result.inliers << "\n";

    return 0;
}
