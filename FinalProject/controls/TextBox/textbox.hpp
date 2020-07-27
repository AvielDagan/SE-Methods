#pragma once
#include <string>
#include "../../Common/Control/Control.hpp"
#include "../Label/Label.hpp"
#include "../../Common/Graphics/Graphics.hpp"
#include "../BorderDrawer/BorderDrawer.hpp"
#include <iostream>
#include <stdlib.h>

class TextBox : public Label{ 

public:
    COORD currentCoord;

    TextBox(short left, short top, short width, BorderDrawer* border, Color textColor, Color backgroundColor);

    void draw(Graphics& g, int x, int y, size_t z);
    bool canGetFocus(){ return true; }
    void mousePressed(int x, int y, bool isLeft);
    void keyDown(int keyCode, char character);
    void setText(string text);
    string getText() { return value; }
};