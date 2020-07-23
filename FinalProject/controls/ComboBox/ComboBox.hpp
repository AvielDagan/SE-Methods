#pragma once

#include "../Panel/Panel.hpp"
#include "../Label/Label.hpp"
#include "../Button/Button.hpp"

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

    ComboBox(short left,short top,short width, short height, BorderDrawer* border, Color textColor, Color BgColor, size_t layer);
    ~ComboBox();
};