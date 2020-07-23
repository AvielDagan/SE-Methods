#pragma once

#include <iostream>
#include "Label.hpp"

class Button : public Label
{
private:
public:
    Button(short left, short top, short with, Label label);
    ~Button();
    void draw(Graphics &g, int x, int y, size_t z);
};