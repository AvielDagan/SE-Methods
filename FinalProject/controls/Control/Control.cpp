#pragma one
#include "Control.hpp"
#include "../BorderDrawer/BorderDrawer.hpp"

Control *Control::_focused = NULL;

Control::Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor) : _left(left), _top(top), _width(width), _height(height), _border(border), _textColor(textColor), _BgColor(BgColor) {}

Control::~Control()
{
    if (_border)
    {
        delete _border;
    }
}

void Control::setFocus(Control &control)
{ //! check for errors!
    _focused = &control;
}

void Control::draw(Graphics &graphics, short left, short top, int width, int height, size_t layer)
{
    graphics.setForeground(getTextColor());
    graphics.setBackground(getBgColor());
    graphics.setCursorVisibility(false);
    _border->draw(graphics, left, top, width, height)
}
