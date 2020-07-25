#include <iostream>
#include "Label.hpp"

// 1 ?
Label::Label(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string value)
    : Control(left, top, width, 1, border, textColor, BgColor), Subject(), title(value){};


string Label::getTitle()
{
    return this->title;
}

// Label::~Label(){}

void Label::setTitle(string title)
{
    this->title = title;
}

void Label::draw(Graphics &g, short left, short top, size_t z)
{
    if (z == 0)
    {
        Control::draw(g, left, top, z);
        g.write(left + 1, top + 1, title);
    }
}