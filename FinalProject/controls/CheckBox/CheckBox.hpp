#pragma once

#include "../Label/Label.hpp"
#include "../Button/Button.hpp"

class CheckBox
{
private:
    Label title;
    Button box;

public:
    void selectBox();
    CheckBox(Label title,Button box);
    ~CheckBox();
};


