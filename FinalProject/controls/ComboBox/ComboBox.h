#pragma once

#include "Panel.h"
#include "Label.h"
#include "Button.h"

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