#pragma once

#include "../CheckList/CheckList.hpp"


class RadioBox : public CheckList
{
public:
    RadioBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor,string labelText);
    virtual void keyDown(int keyCode, char charecter);
};
