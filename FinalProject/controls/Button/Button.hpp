#pragma once

#include "Label.hpp"

class Button : public Label
{
private:
public:
    Button(Label label);
    Button();
    ~Button();
    void draw(Graphics &g, int x, int y, size_t z);
};
