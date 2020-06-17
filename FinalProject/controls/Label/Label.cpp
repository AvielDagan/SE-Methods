#include <iostream>
#include "Label.hpp"

Label::Label(string title) : Control(), Subject(), title(title) {};

string Label::getTitle()
{
    return this->title;
}

void Label::setTitle(string title)
{
    this->title = title;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    if (!z)
        g.write(this->title);

}
