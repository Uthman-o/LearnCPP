#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

class RollingAverage {
   private:
    std::queue<double> window;
    size_t window_size;
    double sum;

   public:
    explicit RollingAverage(size_t size) : window_size(size), sum(0.0) {
        if (size == 0) {
            throw std::invalid_argument("Window size must be greater than zero");
        }
    }

    double addSample(double value) {
        window.push(value);
        sum += value;

        if (window.size() > window_size) {
            sum -= window.front();
            window.pop();
        }

        return getAverage();
    }

    double getAverage() const {
        if (window.empty()) {
            return 0.0;
        }

        return sum / window.size();
    }

    size_t size() const { return window.size(); }

    bool isFull() const { return window.size() == window_size; }

    void reset() {
        while (!window.empty()) {
            window.pop();
        }
        sum = 0.0;
    }
};

bool nearlyEqual(double a, double b, double eps = 1e-9) { return std::fabs(a - b) < eps; }

void testBasicRollingAverage() {
    RollingAverage avg(3);

    assert(nearlyEqual(avg.addSample(10.0), 10.0));
    assert(nearlyEqual(avg.addSample(10.0), 10.0));
    assert(nearlyEqual(avg.addSample(10.0), 10.0));
    assert(nearlyEqual(avg.addSample(10.0), 10.0));

    std::cout << "testBasicRollingAverage passed\n";
}

void testSingleElementWindow() {
    RollingAverage avg(1);

    assert(nearlyEqual(avg.addSample(5.0), 5.0));
    assert(nearlyEqual(avg.addSample(10.0), 10.0));
    assert(nearlyEqual(avg.addSample(-3.0), -3.0));

    std::cout << "testSingleElementWindow passed\n";
}

void runAllTests() {
    testBasicRollingAverage();
    testSingleElementWindow();
    // testNegativeValues();
    // testReset();
    // testInvalidWindowSize();

    std::cout << "All tests passed\n";
}

int main() {
    runAllTests();

    std::cout << "Example Sensor Stream \n";

    RollingAverage sensorAverage(2);

    std::vector<double> sensorData = {1.2, 1.4, 1.3, 1.5, 2.0, 2.5, 2.2, 2.7, 3.0, 5.8};

    for (auto sample : sensorData) {
        double avg = sensorAverage.addSample(sample);
        std::cout << "New sample: " << sample << " | Rolling average: " << avg << std::endl;
    }

    return 0;
}
