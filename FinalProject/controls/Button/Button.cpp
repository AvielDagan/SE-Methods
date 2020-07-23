#include "./Button.hpp"
#include <iostream>

Button::Button(short left, short top, short with, Label label) : Label(label)
{
}

Button::~Button()
{
}

void Button::draw(Graphics &g, int x, int y, size_t z)
{
    // Lable::draw(g,x,y,z)
    std::cout << "drawing from Button" << std::endl;
}