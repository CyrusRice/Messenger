#include "control.h"
#include <iostream>
using namespace std;
int main()
{
    control* controller = new control();
    controller->start();
    delete controller;
    return 0;
}
