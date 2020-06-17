#pragma once

#include "Panel.hpp"
#include "Label.hpp"
#include "Button.hpp"

class ComboBox : public Panel
{
private:
    Label title;
    Button arrow;

public:
    void addLabel(Label);
    void removeLabel(Label);
    void setSelected(Label);
    void onArrowPress();
    void onChosenLabelPress(Label);
    void traverse();

    ComboBox();
    ~ComboBox();
};