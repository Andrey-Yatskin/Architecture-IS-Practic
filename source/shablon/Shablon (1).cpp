#include<iostream>
using namespace std;


class Camera {
public:
    void take_picture() {}
};

class PC {
public:
    void ask() {}
    void answer() {}
    void detect_graffiti() {}
};

class Robot {
private:
    int charge;
public:
    void on() {}
    void off() {}
    void moveOn() {}
    void moveOff() {}
    void move_forward() {}
    void turn_left() {}
    void spray() {}
    void clean() {}
};

class Spray {
public:
    void on() {}
    void off() {}
};

class System {
private:
    Camera ca;
    PC pc;
    Robot robot;
    Spray sp;

public:
    void press_start()
    {
        robot.on();
    }
    void do_spray() {}
    void press_stop()
    {
        robot.off();
    }
};

int main() {
    System robo;
    robo.press_start();
    robo.press_stop();
    cout << "Hello, leather bag!" << endl;
    return 0;
}