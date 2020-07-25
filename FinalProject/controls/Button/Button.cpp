#pragma once
#include "./Button.hpp"
#include <iostream>
#include "../Label/Label.hpp"

Button::Button(short left, short top, short width, short height, BorderDrawer* border, Color textColor, Color BgColor,string title)
 : Label(left,top,width,border,textColor,BgColor,title){}

// Button::~Button()
// {
// }
