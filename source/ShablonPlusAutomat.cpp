#include <iostream>
using namespace std;


class Camera {
public:
};

class PC {
public:
    void callUser() {}
    void callRobot() {}
    void graffitiDetect() {}
};

class Robot {
private:
    int charging;
public:
    void on() {}
    void off() {}
    void moveOn() {}
    void moveOff() {}
    void turnRight() {}
    void turnLeft() {}

};

class Hand {
public:
    void up() {}
    void down() {}
    void left() {}
    void right() {}
};

class Spray {
public:
    void on() {}
    void off() {}
};

class System : Camera, PC, Hand, Robot, Spray {
private:

public:
    void press_start() {}
    void move() {}
    void waiting() {}
    void setHand() {}
    void do_spray() {}
    void rotating() {}
    void press_stop() {}
};


//States

enum Estate
{
    Off = 0,
    On = 1,
    Error = 2,
    waiting = 3,
    move_forward = 4,
    turn_left = 5,
    cleaning = 6,
    settingHand = 7,
};
enum Event
{
    none = 0,
    press_start1 = 1,
    press_stop1 = 2,
    waiting_command = 3,
    receive_move = 4,
    receive_turn = 5,
    receive_clean = 6,
    on_error = 7,
    move_error = 8,
    turn_error = 9,
    clean_error = 10,
    set_hand = 11,
};
struct CEvent
{
    Event event;
    CEvent(Event t) : event(t)
    {

    }
};

class RobotStates : System
{
private:
    int charge = 50;
    Estate state;

public:
    RobotStates()
    {
        state = Estate::Off;
    }
    void detectProcess(CEvent e)
    {
        if (charge > 0 && charge <= 100) {
            switch (state)
            {
            case Estate::Off:
                if (e.event == press_start1)
                {
                    state = Estate::On;
                    press_start();
                    cout << "ON - " << state << endl;
                }
                break;
            case Estate::On:
                if (e.event == waiting_command)
                {
                    state = Estate::waiting;
                    waiting();
                    cout << "Waiting - " << state << endl;
                }
                else if (e.event == on_error)
                {
                    state = Estate::Error;
                    cout << "Error - " << state << endl;
                }
                break;
            case Estate::waiting:
                if (e.event == press_stop1)
                {
                    state = Estate::Off;
                    press_stop();
                    cout << "OFF  - " << state << endl;
                }
                else if (e.event == receive_move)
                {
                    state = Estate::move_forward;
                    move();
                    cout << "Moving forward  - " << state << endl;
                }
                break;
            case Estate::move_forward:
                if (e.event == receive_turn)
                {
                    state = Estate::turn_left;
                    rotating();
                    cout << "Turn left  - " << state << endl;
                }
                else if (e.event == set_hand)
                {
                    state = Estate::settingHand;
                    setHand();
                    cout << "Move hand - " << state << endl;
                }
                else if (e.event == move_error)
                {
                    state = Estate::Error;
                    cout << "Error  - " << state << endl;
                }
                break;
            case Estate::turn_left:
                if (e.event == receive_clean)
                {
                    state = Estate::cleaning;
                    do_spray();
                    cout << "Cleaning  - " << state << endl;
                }
                else if (e.event == turn_error)
                {
                    state = Estate::Error;
                    cout << "Error  - " << state << endl;
                }
                break;
            case Estate::settingHand:
                if (e.event == receive_clean)
                {
                    state = Estate::cleaning;
                    do_spray();
                    cout << "Cleaning  - " << state << endl;
                }
                else if (e.event == receive_move)
                {
                    state = Estate::move_forward;
                    move();
                    cout << "Moving forward  - " << state << endl;
                }
                break;
            case Estate::cleaning:
                if (e.event == clean_error)
                {
                    state = Estate::Error;
                    cout << "Error  - " << state << endl;
                }
                break;
            }
        }
        else if (charge <= 0) {
            state = Estate::Off;
            press_stop();
        }

    }
};

CEvent get_event()
{
    int input;
    cin >> input;
    cout << endl << "-------------------" << endl;
    if (input == 0) return CEvent(Event::none);
    else if (input == 1) return CEvent(Event::press_start1);
    else if (input == 2) return CEvent(Event::press_stop1);
    else if (input == 3) return CEvent(Event::waiting_command);
    else if (input == 4) return CEvent(Event::receive_move);
    else if (input == 5) return CEvent(Event::receive_turn);
    else if (input == 6) return CEvent(Event::receive_clean);
    else if (input == 7) return CEvent(Event::on_error);
    else if (input == 8) return CEvent(Event::move_error);
    else if (input == 9) return CEvent(Event::turn_error);
    else if (input == 10) return CEvent(Event::clean_error);
    else if (input == 11) return CEvent(Event::set_hand);

}
int main()
{
    setlocale(LC_ALL, "ru");
    RobotStates Oleg;
    while (1)
    {
        CEvent t = get_event();
        Oleg.detectProcess(t);
    }

    System rob1{};
    rob1.press_start();
    rob1.press_stop();
    return 0;
}