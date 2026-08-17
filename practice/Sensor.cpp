#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

using namespace std;

// Abstract Sensor

class Sensor {
   protected:
    int id_;

   public:
    explicit Sensor(int id) : id_(id) {}

    virtual ~Sensor() = default;
    virtual void start() = 0;
    virtual void read() = 0;
    virtual string name() const = 0;
};

// Camera

class CameraSensor : public Sensor {
   public:
    explicit CameraSensor(int id) : Sensor(id) {}

    void start() override { cout << "Starting Camera " << id_ << endl; }
    void read() override { cout << "Camera " << id_ << " reading image" << endl; }
    string name() const override { return "Camera"; }
};

// Lidar Sensor

class LidarSensor : public Sensor {
   public:
    explicit LidarSensor(int id) : Sensor(id) {}

    void start() override { cout << "Starting Lidar " << id_ << endl; }
    void read() override { cout << "Lidar " << id_ << " reading pointcloud" << endl; }
    string name() const override { return "Lidar"; }
};

// IMU Sensor
class IMUSensor : public Sensor {
   public:
    explicit IMUSensor(int id) : Sensor(id) {}

    void start() override { cout << "Starting IMU " << id_ << endl; }
    void read() override { cout << "Lidar " << id_ << " reading accel + gyro" << endl; }
    string name() const override { return "IMU"; }
};

// Factory

class SensorFactory {
   public:
    static unique_ptr<Sensor> createSensor(const string& type, int id) {
        if (type == "Camera") return make_unique<CameraSensor>(id);
        if (type == "Lidar") return make_unique<LidarSensor>(id);
        if (type == "IMU") return make_unique<IMUSensor>(id);

        return nullptr;
    }
};

// Thread Safe Singleton

class SensorManager {
   private:
    vector<unique_ptr<Sensor>> sensors_;

    // Protect shared sensor container
    mutable mutex mutex_;

    SensorManager() = default;

   public:
    SensorManager(const SensorManager&) = delete;

    SensorManager& operator=(const SensorManager&) = delete;

    static SensorManager& getInstance() {
        static SensorManager instance;
        return instance;
    }

    void addSensor(unique_ptr<Sensor> sensor) {
        if (!sensor) return;

        lock_guard<mutex> lock(mutex_);

        sensors_.push_back(move(sensor));
    }

    void startAll() {
        lock_guard<mutex> lock(mutex_);
        for (const auto& sensor : sensors_) {
            sensor->start();
        }
    }

    void readAll() {
        lock_guard<mutex> lock(mutex_);
        for (const auto& sensor : sensors_) {
            sensor->read();
        }
    }

    void printSensors() const {
        lock_guard<mutex> lock(mutex_);
        for (const auto& sensor : sensors_) {
            cout << sensor->name() << endl;
        }
    }

    size_t size() const {
        lock_guard<mutex> lock(mutex_);

        return sensors_.size();
    }
};

int main() {
    SensorManager& manager = SensorManager::getInstance();

    manager.addSensor(SensorFactory::createSensor("Camera", 1));
    manager.addSensor(SensorFactory::createSensor("Lidar", 2));
    manager.addSensor(SensorFactory::createSensor("IMU", 3));

    manager.printSensors();
    manager.startAll();
    manager.readAll();

    return 0;
}
