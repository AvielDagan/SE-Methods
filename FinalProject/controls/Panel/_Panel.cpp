#include "./Panel.hpp"
#include <iostream>

Panel::Panel(short left, short top, BorderDrawer *border, Color textColor, Color BgColor, size_t layer)
    : Control(left, top, 1, 1, border, textColor, BgColor)
{
    panelSize();
}
Panel::~Panel()
{
}
Control *Panel::getControls(int i)
{
    return controls[i];
}
bool Panel::addControl(Control *control)
{
    if (control != nullptr)
    {
        try
        {
            controls.push_back(control);
            if (getFocus() == nullptr && control->canGetFocus())
            {
                setFocus(*control);
            }
        }
        catch (...)
        {
            return false;
        }
        return true;
    }
    return false;
}
// bool Panel::addControl(Control *control)
// {
//     controls.push_back(control);
//     setFocus(*control);
// }
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
    if (z == 0)
    {
        Control::draw(g, left, top, z);
        for (int i = 0; i < controls.size(); ++i)
        {
            controlLeft = controls[i]->getLeft();
            controlTop = controls[i]->getTop();
            g.setForeground(controls[i]->getTextColor());
            g.setBackground(controls[i]->getBgColor());
            controls[i]->draw(g, left + controlLeft + 1, top + controlTop + 1, z);
        }
    }
    if (z == 1)
    {
        if (getFocusIndex() != -1)
        {
            controlLeft = controls[focusIndex]->getLeft();
            controlTop = controls[focusIndex]->getTop();
            g.setForeground(controls[focusIndex]->getTextColor());
            g.setBackground(controls[focusIndex]->getBgColor());
            controls[focusIndex]->draw(g, left + controlLeft + 1, top + controlTop + 1, 0);
        }
    }
}

int Panel::getFocusIndex()
{
    Control *tempPtr = getFocus();
    for (int i = 0; i < controls.size(); ++i)
    {
        if (controls[i] == tempPtr)
        {
            focusIndex = i;
            return i;
        }
        else if (controls[i]->getFocusIndex() != -1)
        {
            focusIndex = i;
            return i;
        }
    }
    focusIndex = -1;
    return -1;
}

void Panel::getAllControls(vector<Control *> *controls)
{
    for (int i = 0; i < this->controls.size(); ++i)
    {
        controls->push_back(this->controls[i]);
        this->controls[i]->getAllControls(controls);
    }
}
void Panel::keyDown(int keyCode, char charecter)
{
    if (getFocusIndex() != -1)
    {
        controls[focusIndex]->keyDown(keyCode, charecter);
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
        if (tTop + tHeight > sHeight)
        {
            // std::cout << "inside sHeight" << std::endl;
            sHeight = tTop + tHeight;
        }
        if (tLeft + tWidth > sWidth)
        {
            sWidth = tLeft + tWidth;
        }
    }

    setWidth(sWidth + 4);
    setHeight(sHeight + 4);
}
// notify();
