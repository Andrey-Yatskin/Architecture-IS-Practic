 #include <iostream>

using namespace std;
enum Estate
{
    Off = 0,
    On = 1,
    Error = 2,
    waiting = 3,
    move_forward = 4,
    turn_left = 5,
    cleaning = 6,
};
enum Event
{
    none = 0,
    press_start,
    press_stop,
    waiting_command,
    receive_move,
    receive_turn,
    receive_clean,
    on_error,
    move_error,
    turn_error,
    clean_error,
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
            if (e.event == waiting_command)
            {
                state = Estate::waiting;
            }
            if (e.event == on_error)
            {
                state = Estate::Error;
            }
            break;
        case Estate::waiting:
            if (e.event == press_stop)
            {
                state = Estate::Off;
            }
            if (e.event == receive_move)
            {
                state = Estate::move_forward;
            }
            break;
        case Estate::move_forward:
            if (e.event == receive_turn)
            {
                state = Estate::turn_left;
            }
            if (e.event == move_error)
            {
                state = Estate::Error;
            }
            break;
        case Estate::turn_left:
            if (e.event == receive_clean)
            {
                state = Estate::cleaning;
            }
            if (e.event == turn_error)
            {
                state = Estate::Error;
            }
            break;
        case Estate::cleaning:
            if (e.event == clean_error)
            {
                state = Estate::Error;
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