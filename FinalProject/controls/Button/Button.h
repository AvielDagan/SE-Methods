#pragma once
#include "Label.h"
#include <iostream>
#include "../Graphics/Graphics.h"

class Button : public Label
{
private:
public:
    Button(short left, short top, short width,Label label);
    ~Button();
    void draw(Graphics &g, int x, int y, size_t z);
};
