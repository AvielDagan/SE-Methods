#include "Control.hpp"

Control *Control::_focused = NULL;


Control::Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor) 
: _left(left), _top(top), _width(width), _height(height), _border(border), _textColor(textColor), _BgColor(BgColor) {}


Control::~Control()
{
    // if (_border)
    // {
    //     delete _border;
    // }
}

// static void Control::setFocus(Control &control)
// { //! check for errors!
//     _focused = &control;
// }

void Control::draw(Graphics &graphics, short left, short top, size_t layer)
{
    graphics.setForeground(getTextColor());
    graphics.setBackground(getBgColor());
    graphics.setCursorVisibility(false);
    _border->drawBorder(graphics, left, top, this->_width + 2, this->_height + 2);
}
