#pragma once

#include "../Panel/Panel.hpp"
#include "../../Common/Control/Control.hpp"
#include "../Button/Button.hpp"
#include "../Label/Label.hpp"
#include <string>

class NumericBox : public Panel
{
private:
    int value;
    int minVal;
    int maxVal;
    Button subtract;
    Button add;
    Label currVal;

public:
    void increase();
    void decrease();
    int getVal();
    void setVal(int);
    int getMin();
    int setMin(int);
    int getMax();
    int setMax(int);
    bool setValue(int);
    void draw(Graphics &g, int x, int y, size_t z);
    void notify(string text);
    NumericBox(short left, short top, int maxVal, int minVal, BorderDrawer *border, Color textColor, Color backgroundColor);
    ~NumericBox();
};