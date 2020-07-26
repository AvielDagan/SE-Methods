#include "./Control.h"
#include "../../Controls/NullBorderDrawer/NullBorderDrawer.hpp"
// #include "../Controls/MessageBox.h"
#include <iostream>
using namespace std;

Control *Control::focusedControl = nullptr;
bool Control::messageBoxLock = false;

Control::Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color backgroundColor) : left(left), top(top), width(width), height(height), border(border), textColor(textColor), backgroundColor(backgroundColor), show(true) {}

Control::~Control()
{
    if (border)
    {
        delete border;
    }
}

// void Control::setFocus(Control& control) {
//     if((focusedControl != &control) && (control.canGetFocus() /*|| (typeid(control) == typeid(semMessageBox))*/)) {
//         focusedControl = &control;
//     }
// }

void Control::setMessageBoxLock(bool isLocked)
{ //! ?
    messageBoxLock = isLocked;
}

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
            borderPadding = 3;
            // g.setForeground(Color::White);
            // g.setBackground(Color::Black);
        }
        // else
        // {

        g.setForeground(getTextColor());
        g.setBackground(getBackgroundColor());
        // }
        g.setCursorVisibility(false);

        border->drawBorder(g, x, y, width + borderPadding, height + borderPadding);
    }
}

void Control::drawFocus(Graphics &g, int x, int y, size_t z)
{
    int borderPadding = 2;
    g.setForeground(Color::White);
    g.setBackground(Color::Black);
    g.setCursorVisibility(false);

    border->drawBorder(g, x, y, width + borderPadding, height + borderPadding);
}

void Control::setShow(bool f) {
    this->show = f;
}