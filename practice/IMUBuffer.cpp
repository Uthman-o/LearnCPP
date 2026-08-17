#include <Eigen/Dense>
#include <cstddef>
#include <deque>
#include <iostream>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <utility>

#include "Eigen/src/Core/Matrix.h"

struct ImuMeasurement {
    double timestamp;
    Eigen::Vector3d accel;
    Eigen::Vector3d gyro;
};

class ImuBuffer {
   private:
    size_t maxSize_;
    std::deque<ImuMeasurement> buffer_;
    mutable std::mutex mutex_;

   public:
    explicit ImuBuffer(size_t maxSize) : maxSize_(maxSize) {
        if (maxSize_ < 2) {
            throw std::invalid_argument("IMU buffer must be atleast 2");
        }
    }

    void add(const ImuMeasurement& m) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!buffer_.empty() && m.timestamp < buffer_.back().timestamp) {
            throw std::invalid_argument(" Measurements must arrive in chronological order");
        }

        buffer_.push_back(m);

        if (buffer_.size() > maxSize_) {
            buffer_.pop_front();
        }
    }

    std::pair<ImuMeasurement, ImuMeasurement> getBoundingMeasurements(double timestamp) const {
        std::lock_guard<std::mutex> lock(mutex_);
        if (buffer_.size() < 2) {
            throw std::runtime_error("Insufficient Measurements");
        }

        if (timestamp < buffer_.front().timestamp || timestamp > buffer_.back().timestamp) {
            throw std::out_of_range("Timestamp outside buffer");
        }

        for (size_t i = 1; i < buffer_.size(); ++i) {
            if (buffer_[i].timestamp >= timestamp) {
                return {buffer_[i - 1], buffer_[i]};
            }
        }
        throw std::runtime_error("Couldn't find bounding measurements");
    }

    size_t size() const { return buffer_.size(); }

    bool empty() const { return buffer_.empty(); }

    void printMeasurement(const std::string& name, const ImuMeasurement& m) {
        std::cout << name << '\n';
        std::cout << "Timestamp: " << m.timestamp << '\n';
        std::cout << "Accel: " << m.accel.transpose() << '\n';
        std::cout << "Gyro: " << m.gyro.transpose() << '\n';
    }
};

int main() {
    try {
        ImuBuffer buffer(5);

        ImuMeasurement m1{1.0, Eigen::Vector3d(0.1, 0.0, 9.81), Eigen::Vector3d(0.01, 0.02, 0.03)};

        ImuMeasurement m2{1.1, Eigen::Vector3d(0.2, 0.0, 9.80), Eigen::Vector3d(0.02, 0.02, 0.04)};

        ImuMeasurement m3{1.2, Eigen::Vector3d(0.3, 0.1, 9.79), Eigen::Vector3d(0.03, 0.03, 0.05)};

        ImuMeasurement m4{1.3, Eigen::Vector3d(0.4, 0.1, 9.78), Eigen::Vector3d(0.04, 0.04, 0.06)};

        buffer.add(m1);
        buffer.add(m2);
        buffer.add(m3);
        buffer.add(m4);

        double queryTime = 1.3;

        auto measurements = buffer.getBoundingMeasurements(queryTime);

        const auto& before = measurements.first;
        const auto& after = measurements.second;

        std::cout << "Query timestamp: " << queryTime << "\n\n";

        buffer.printMeasurement("Before:", before);
        std::cout << "\n";
        buffer.printMeasurement("After:", after);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
