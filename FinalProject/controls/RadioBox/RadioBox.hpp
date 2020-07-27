#pragma once

#include "../CheckList/CheckList.hpp"


class RadioBox : public CheckList
{
private:

    
public:
    // bool addSelectedItem(CheckBox cb);
    RadioBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor,string labelText);
    // ~RadioBox();
    virtual void keyDown(int keyCode, char charecter);
};
