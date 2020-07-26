#pragma once

#include <iostream>
#include "../Label/Label.h"
#include <vector>

class Button : public Label
{
public:
    Button(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string title,Observer* observ);
    // ~Button();;
    void keyDown(int keyCode, char character);
    bool canGetFocus(){ return true; }

private:

};