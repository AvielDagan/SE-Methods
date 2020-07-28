#pragma once

#include "../Panel/Panel.hpp"
#include "../Button/Button.hpp"
#include "../Label/Label.hpp"
#include <sstream> 

class NumericBox : public Panel
{
private:
    int value;
    int minVal;
    int maxVal;
    Button subtract;
    Button add;
    Label title;
    
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
    void keyDown(int keyCode, char charecter);
    void draw(Graphics& g, int x, int y, size_t z);

    NumericBox(short left, short top, int maxVal, int minVal, BorderDrawer* border, Color textColor, Color backgroundColor);
    ~NumericBox();
};