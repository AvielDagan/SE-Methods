#pragma once

#include <iostream>
#include "../Label/Label.hpp"

class Button : public Label
{
public:
    Button(short left, short top, short width, short height, BorderDrawer* border, Color textColor, Color BgColor,string title);
    // ~Button();
};