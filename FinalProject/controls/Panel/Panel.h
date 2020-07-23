#pragma once

#include <vector>
#include <windows.h>
#include "../Control/Control.h"

using namespace std;

class Panel : public Control
{
private:
    vector<Control> controls;
    vector<Control> controllersLocation;

public:
    vector<Control> getControls();
    void setControl(Control control);
    COORD getControlLocation();
    void setControlLocation(COORD);
    // draw();
    // notify();
    Panel();
    ~Panel();
};