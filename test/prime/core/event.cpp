#include "../../../native/prime/core/event.hpp"
#include<iostream>

using namespace dty;
using namespace std;

class Int32Event : public EventArgs
{
    __PUB__ int32 __VARIABLE__ Event;
};

void Fun1(object sender, EventArgs e)
{
    cout << "Fun1 :: " << endl;
}

void Fun2(object sender, EventArgs e)
{
    cout << "Fun2 :: " << endl;
}

void Fun3(object sender, EventArgs e)
{
    cout << "Fun3 :: " << endl;
}

int main()
{
    EventHandler<EventArgs> handler;
    Int32Event e;
    e.Event = 1;

    handler.AddHandler(1, Fun1);
    handler.Invoke(null, e);

    cout << "#####################" << endl;

    e.Event = 2;
    handler.AddHandler(2, Fun2);
    handler.Invoke(null, e);

    cout << "#####################" << endl;

    e.Event = 3;
    handler.AddHandler(3, Fun3);
    handler.Invoke(null, e);

    cout << "#####################" << endl;

    e.Event = 4;
    handler.RemoveHandler(2);
    handler.Invoke(null, e);

    return 0;
}