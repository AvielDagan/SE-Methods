#include <iostream>
#include "Label.hpp"

Label::Label(short left, short top, short width, short height,BorderDrawer *border, Color textColor, Color BgColor, string value) : Control(left, top, width, height, border, textColor, BgColor), Subject(), title(value){}

string Label::getTitle()
{
    return title;
}

// Label::~Label(){}

void Label::setTitle(string title)
{
    this->title = title;
}

void Label::draw(Graphics &g, short left, short top, short width, short height, size_t z)
{
    if (!z)
        Control::draw(g, left, top, width, height, z);
    g.write(left + 1, top + 1, title);
}