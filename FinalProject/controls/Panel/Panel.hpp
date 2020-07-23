#pragma once

#include <vector>
#include <windows.h>
#include "../../Common/Control/Control.hpp"

using namespace std;

class Panel : public Control
{
private:
    vector<Control*> controls;
    vector<Control*> controllersLocation;

public:
    vector<Control*> getControls();
    void addControl(Control* control);
    COORD getControlLocation();
    void setControlLocation(COORD);
    void draw(Graphics& g,short left, short top,size_t z);
    void panelSize();
    // notify();
    Panel(short left,short top,short width, short height, BorderDrawer* border, Color textColor, Color BgColor, size_t layer);
    ~Panel();
};