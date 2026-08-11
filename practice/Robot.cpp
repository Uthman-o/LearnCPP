#include <iostream>
#include <memory>
#include <string>

class Robot {
   private:
    std::string name;
    double x;
    double y;

   public:
    Robot(std::string robotName, double startX, double startY)
        : name(robotName), x(startX), y(startY) {
        std::cout << "Robot created\n";
    }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void printPosition() const { std::cout << name << " is at (" << x << ", " << y << ")" << '\n'; }

    double getX() const { return x; }
    void setX(double newX) { x = newX; }

    ~Robot() { std::cout << name << " Robot Destroyed\n"; }
};

int main() {
    Robot robot1("R1", 0.0, 3.0);
    robot1.setX(1.0);
    robot1.move(2.0, 3.5);
    robot1.printPosition();
    double X = robot1.getX();

    std::cout << X << '\n';

    auto r1 = std::make_unique<Robot>("Rbt1", 0, 0);

    r1->move(1, 2);
    r1->printPosition();

    return 0;
}
