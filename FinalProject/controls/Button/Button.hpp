#pragma once
#include <iostream>
#include "../Label/Label.hpp"

class Button : public Label
{
public:
    Button(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string title,Observer* observ);
    // ~Button();;
    void keyDown(int keyCode, char character);
    bool canGetFocus(){ return focused; };
    void setCanClick(bool f) {focused=f;};

private:
bool focused = true;

};