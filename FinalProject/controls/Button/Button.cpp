#include "./Button.hpp"
#include <iostream>

Button::Button(short left, short top, short width, short height, BorderDrawer* border, Color textColor, Color BgColor,string title) : Label(left,top,width,height,border,textColor,BgColor,title){}

Button::~Button()
{
}
