// AeroVect-style OOP design problem: Fleet Manager
// Compile: g++ -std=c++17 -Wall -fsanitize=address fleet_manager.cpp -o fleet && ./fleet
//
// Design goals demonstrated here:
//   - Encapsulation: state is private, exposed via const getters
//   - Inheritance + polymorphism: Vehicle base, concrete tractor types
//   - Virtual destructor: safe deletion through base pointer
//   - Ownership: FleetManager OWNS vehicles via unique_ptr; queries return
//     non-owning raw pointers (an "observer", never deleted by the caller)

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

// --- small value type ---------------------------------------------------
struct Point {
    double x = 0.0;
    double y = 0.0;
};

// Euclidean distance. Free function because it's a relationship between two
// Points, not a behavior owned by one of them.
double distance(const Point& a, const Point& b) {
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);  // std::hypot(dx, dy) is also fine
}

// Strongly-typed states beat raw ints: type-safe, no implicit conversions.
enum class State { Idle, Driving, Charging, Stopped };

const char* toString(State s) {
    switch (s) {
        case State::Idle:
            return "Idle";
        case State::Driving:
            return "Driving";
        case State::Charging:
            return "Charging";
        case State::Stopped:
            return "Stopped";
    }
    return "Unknown";
}

// --- base class ----------------------------------------------------------
class Vehicle {
   public:
    Vehicle(int id, Point pos, double battery)
        : id_(id), pos_(pos), battery_(battery), state_(State::Idle) {}

    // CRITICAL: virtual destructor. Deleting a derived object through a
    // Vehicle* (which is what FleetManager holds) is undefined behavior
    // without this. Interviewers specifically look for it.
    virtual ~Vehicle() = default;

    // Pure virtual -> Vehicle is abstract; every concrete type must name itself.
    virtual std::string type() const = 0;

    // Virtual so derived types can tighten the rule (cargo needs more charge).
    virtual bool isAvailable() const { return state_ == State::Idle && battery_ > 20.0; }

    // Behavior that mutates state goes through named methods, not public fields.
    void dispatchTo(const Point& target) {
        pos_ = target;
        state_ = State::Driving;
    }
    void charge() {
        state_ = State::Charging;
        battery_ = 100.0;
    }

    // const getters: read-only access to private state.
    int id() const { return id_; }
    Point position() const { return pos_; }
    double battery() const { return battery_; }
    State state() const { return state_; }

   private:
    // Declaration order matches the constructor's init list (avoids -Wreorder).
    // All state private; derived classes read it through the public getters
    // rather than reaching in -> tighter encapsulation.
    int id_;
    Point pos_;
    double battery_;
    State state_;
};

// --- derived types -------------------------------------------------------
class BaggageTractor : public Vehicle {
   public:
    using Vehicle::Vehicle;  // inherit the constructor
    std::string type() const override { return "BaggageTractor"; }
};

class CargoTractor : public Vehicle {
   public:
    using Vehicle::Vehicle;
    std::string type() const override { return "CargoTractor"; }

    // Cargo hauls heavier loads -> demand a higher charge before dispatch.
    bool isAvailable() const override { return state() == State::Idle && battery() > 40.0; }
};

// --- manager -------------------------------------------------------------
class FleetManager {
   public:
    // Takes ownership. The unique_ptr makes the transfer explicit at call sites.
    void addVehicle(std::unique_ptr<Vehicle> v) { vehicles_.push_back(std::move(v)); }

    // Returns a NON-OWNING observer pointer (nullptr if none available).
    // Caller must not delete it; the fleet still owns the object.
    Vehicle* findNearestAvailable(const Point& target) const {
        Vehicle* best = nullptr;
        double bestDist = std::numeric_limits<double>::max();
        for (const auto& v : vehicles_) {
            if (!v->isAvailable()) continue;
            const double d = distance(v->position(), target);
            if (d < bestDist) {
                bestDist = d;
                best = v.get();
            }
        }
        return best;  // O(n); fine for a fleet. Note this aloud in the interview.
    }

    // Find + dispatch in one call. Returns the dispatched vehicle, or nullptr.
    Vehicle* dispatchNearest(const Point& target) {
        Vehicle* v = findNearestAvailable(target);
        if (v) v->dispatchTo(target);
        return v;
    }

    void printStatus() const {
        std::cout << "--- Fleet status (" << vehicles_.size() << " vehicles) ---\n";
        for (const auto& v : vehicles_) {
            std::cout << "  #" << v->id() << "  " << v->type() << "  pos=(" << v->position().x
                      << "," << v->position().y << ")"
                      << "  batt=" << v->battery() << "  " << toString(v->state())
                      << (v->isAvailable() ? "  [available]" : "") << "\n";
        }
    }

   private:
    std::vector<std::unique_ptr<Vehicle>> vehicles_;
};

// --- tiny driver / test cases -------------------------------------------
int main() {
    FleetManager fleet;
    fleet.addVehicle(std::make_unique<BaggageTractor>(1, Point{0, 0}, 90));
    fleet.addVehicle(std::make_unique<BaggageTractor>(2, Point{10, 10}, 15));  // low batt
    fleet.addVehicle(std::make_unique<CargoTractor>(3, Point{2, 2}, 30));      // < 40 -> busy
    fleet.addVehicle(std::make_unique<CargoTractor>(4, Point{3, 3}, 80));

    fleet.printStatus();

    Point job{10, 10};
    std::cout << "\nDispatching nearest available to (1,1)...\n";
    if (Vehicle* v = fleet.dispatchNearest(job)) {
        std::cout << "  -> sent #" << v->id() << " (" << v->type() << ")\n";
    } else {
        std::cout << "  -> none available\n";
    }
    // Expected: #4 wins. #2 too low, #3 cargo<40 unavailable, #4 (d~2.83)
    // is nearer than #1 (d~1.41)? -> #1 d=1.41, #4 d=2.83, so #1 wins.

    std::cout << "\n";
    fleet.printStatus();
    return 0;
}
