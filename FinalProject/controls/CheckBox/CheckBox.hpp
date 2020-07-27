#pragma once

#include "../Label/Label.hpp"
#include "../Button/Button.hpp"

class CheckBox : public Button
{
private:
    string selectedString;
    string unselectedString;
    bool selected;

public:
    string getSelectedString() {return selectedString;}
    void setSelectedString(string str) { selectedString = str; };
    void setUnselectedString(string str) { unselectedString = str; };
    bool getSelected() { return selected; };
    void setSelected(bool selected) { this->selected = selected; };

    virtual void draw(Graphics& g, int x, int y, size_t z);
    virtual void keyDown(int keyCode, char charecter);
    virtual bool canGetFocus() { return true; };
    CheckBox(short left, short top, short width,BorderDrawer* buttonBorder, Color textColor, Color backgroundColor, string value);
    ~CheckBox();
};


