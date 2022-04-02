#include <iostream>

using namespace std;
enum Estate
{
    Off = 0,
    On = 1,
    Error = 2,
    Waiting = 3,
    Moving = 4,

};
enum Event
{
    none = 0,
    press_start,
    press_stop,
    receive_move,
    receive_clean,
};
struct CEvent
{
    Event event;
    CEvent(Event t) : event(t)
    {

    }
};

class Robot
{
private:
    int charge = 50;
    Estate state;

public:
    Robot()
    {
        state = Estate::Off;
    }
    void detectProcess(CEvent e)
    {
        switch (state)
        {
        case Estate::Off:
            if (e.event == press_start)
            {
                state = Estate::On;
            }
            break;
        case Estate::On:
            if (e.event == receive_move)
            {
                state = Estate::Moving;
            }
            break;
        }

    }
};

CEvent get_event()
{
    char input;
    cin >> input;
    return CEvent(Event::none);
}
int main()
{
    /*Robot Oleg;
    while (1)
    {
        CEvent t = get_event();
        Oleg.detectProcess(t);
    }
    */
    cout << "Hello World";

    return 0;
}