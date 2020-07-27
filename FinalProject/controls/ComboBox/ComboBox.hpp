#pragma once

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.hpp"
#include "../BorderDrawer/BorderDrawer.hpp"
#include "string"
class ComboBox : public Panel
{
private:
    Label text;
    int curr;
    bool optionsIsOpen;
    short marginTop;

public:
    ComboBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor);
    void addToList(string toAdd);
    void draw(Graphics &g, int x, int y, size_t z);
    void keyDown(int keyCode, char character);
    void notify(string s);
    bool canGetFocus(){ return true; };
    ~ComboBox(){};
};
