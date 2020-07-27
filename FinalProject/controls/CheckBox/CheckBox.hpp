#pragma once
#include <iostream>
#include "../Button/Button.hpp"
#include <string>
// #include "../SingleBorderDrawer/SingleBorderDrawer.hpp"


using namespace std;

class CheckBox : public Button
{
public:
    CheckBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string title, Observer *observ);
    // ~CheckBox(){};

    void selectBox();
    void draw(Graphics &g, int x, int y, size_t z);
    bool getIsSelected() {return isSelected;};

private:
    bool isSelected;
    string cbValue;
};