#include "../../../native/prime/core/property.hpp"
#include<iostream>

using namespace dty;
using namespace std;

int main()
{
    Property<int32> prop;

    prop.Set(128);
    cout << prop.Get() << endl;

    prop.Set(100);
    cout << prop.Get() << endl;

    prop = 200;
    cout << prop.Get() << endl;

    int32 value = prop;
    cout << value << endl;
    cout << prop << endl;

    return 0;
}