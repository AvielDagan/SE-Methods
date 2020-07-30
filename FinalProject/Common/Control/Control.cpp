#include "./Control.hpp"
#include "../../Controls/NullBorderDrawer/NullBorderDrawer.hpp"
#include <iostream>
using namespace std;

Control *Control::focusedControl = nullptr;

Control::Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color backgroundColor) : left(left), top(top), width(width), height(height), border(border), textColor(textColor), backgroundColor(backgroundColor), show(true) {}

Control::~Control()
{
    if (border)
    {
        delete border;
    }
}

void Control::setFocus(Control &control)
{
    if ((focusedControl != &control) && (control.canGetFocus()))
    {
        focusedControl = &control;
    }
};

void Control::setBorder(BorderDrawer *border)
{
    if (this->border)
    {
        delete this->border;
    }
    this->border = border;
}

void Control::draw(Graphics &g, int x, int y, size_t z)
{
    if (this->show == true)
    {

        int borderPadding = 2;
        if (getFocus() == this)
        {
            g.setForeground(this->getBackgroundColor());
            g.setBackground(this->getTextColor());
        }
        else
        {
            g.setForeground(getTextColor());
            g.setBackground(getBackgroundColor());
        }
        g.setCursorVisibility(false);

        border->drawBorder(g, x, y, width + borderPadding, height + borderPadding);
    }
}

void Control::setShow(bool f)
{
    this->show = f;
}