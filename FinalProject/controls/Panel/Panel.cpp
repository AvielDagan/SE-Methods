#include "./Panel.hpp"
#include <iostream>

Panel::Panel(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor, size_t layer)
    : Control(left, top, width, height, border, textColor, BgColor)
{
    panelSize();
}
Panel::~Panel()
{
}
vector<Control *> Panel::getControls()
{
    return controls;
}
void Panel::addControl(Control *control)
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
    panelSize();
    Control::draw(g, left, top, 0, 0, z);
    for (int i = 0; i < controls.size(); ++i)
    {
        controlLeft = controls[i]->getLeft();
        controlTop = controls[i]->getTop();
        g.setForeground(controls[i]->getTextColor());
        g.setBackground(controls[i]->getBgColor());
        controls[i]->draw(g, left + controlLeft, top + controlTop, controls[i]->getWidth(), controls[i]->getHeight(), z);
    }
}

void Panel::panelSize()
{
    short sWidth = 0, sHeight = 0, tLeft = 0, tTop = 0, tWidth = 0, tHeight = 0;
    for (int i = 0; i < controls.size(); ++i)
    {
        tLeft = controls[i]->getLeft();
        tTop = controls[i]->getTop();
        tWidth = controls[i]->getWidth();
        tHeight = controls[i]->getHeight();

        // calc max size
        if(tTop + tHeight > sHeight) {
            std::cout << "inside sHeight" << std::endl;
            sHeight = tTop + tHeight;   
        }
        if(tLeft + tWidth > sWidth) {
            sWidth = tLeft + tWidth;
        }
    }

    setWidth(sWidth + 4);
    setHeight(sHeight + 4);
}
// notify();
