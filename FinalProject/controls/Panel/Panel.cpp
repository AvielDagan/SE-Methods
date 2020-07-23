#include "./Panel.hpp"

Panel::Panel(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor, size_t layer)
    : Control(left, top, width, height, border, textColor, BgColor)
{
}
Panel::~Panel()
{
}
vector<Control *> Panel::getControls()
{
    return controls;
}
void Panel::addControl(Control* control)
{
    controls.push_back(control);
}
COORD Panel::getControlLocation()
{
}
void Panel::setControlLocation(COORD)
{
}

void Panel::draw(Graphics &g, short left, short top, size_t z)
{
    short controlLeft;
    short controlTop;
    Control::draw(g,left,top,0,0,z);
    for (int i = 0; i < controls.size(); ++i)
    {
        controlLeft = controls[i]->getLeft();
        controlTop = controls[i]->getTop();
        g.setForeground(controls[i]->getTextColor());
        g.setBackground(controls[i]->getBgColor());
        controls[i]->draw(g,left + controlLeft,top + controlTop,controls[i]->getWidth(),controls[i]->getHeight(),z);
    }
}
// notify();
