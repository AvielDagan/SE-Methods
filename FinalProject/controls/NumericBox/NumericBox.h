#pragma once

#include "Panel.h"
#include "Button.h"
#include "Label.h"

class NumericBox : public Panel
{
private:
    int value;
    int minVal;
    int maxVal;
    Button minButton;
    Button maxButton;
    Label title;

public:
    void increase();
    void decrease();
    int getVal();
    void setVal(int);
    int getMin();
    void setMin(int);
    int getMax();
    void setMax(int);
    bool setValue(int);//return

    NumericBox();
    ~NumericBox();
};