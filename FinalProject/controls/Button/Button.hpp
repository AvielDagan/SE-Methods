#pragma once

#include <iostream>
#include "../Label/Label.h"

class Button : public Label
{
public:
    Button(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string title);
    // ~Button();
    void keyDown(int keyCode, char character);
};