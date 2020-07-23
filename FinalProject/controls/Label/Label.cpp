#include <iostream>
#include "Label.hpp"

Label::Label(short left, short top, short width, string value) : Control(left, top, width), Subject(), title(title){};

string Label::getTitle()
{
    return title;
}

void Label::setTitle(string title)
{
    this->title = title;
}

void Label::draw(Graphics &g, int x, int y, size_t z)
{
    if (!z)
        Control::draw(g, x, y, z);
    g.write(x + 1, y + 1, title);
}