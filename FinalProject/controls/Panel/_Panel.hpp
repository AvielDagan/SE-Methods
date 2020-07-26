#pragma once

#include <vector>
#include <windows.h>
#include "../../Common/Control/Control.h"

using namespace std;

class Panel : public Control
{
public:
    Panel(short left, short top, BorderDrawer *border, Color textColor, Color BgColor, size_t layer);
    ~Panel();
    bool addControl(Control *control);
    Control *getControls(int i);
    int getFocusIndex();

    virtual void draw(Graphics &g, short left, short top, size_t z);
    virtual void keyDown(int keyCode, char charecter);
    virtual void getAllControls(vector<Control *> *controls);
    COORD getControlLocation();
    void setControlLocation(COORD);
    // notify();

private:
    vector<Control*> controls;
    vector<Control*> controllersLocation;
    void panelSize();
    int focusIndex;
};