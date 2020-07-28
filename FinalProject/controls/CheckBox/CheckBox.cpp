#include "CheckBox.hpp"
#include "../NullBorderDrawer/NullBorderDrawer.hpp"
// #include "../SingleBorderDrawer/SingleBorderDrawer.hpp"

CheckBox::CheckBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color BgColor, string title,Observer* observ) :
Button( left,top,  15, border, textColor, BgColor, title, observ)
 {
    isSelected = false;
    cbValue = title;
}


void CheckBox::selectBox() {
    isSelected = !isSelected;
}

void CheckBox::draw(Graphics &g, int x, int y, size_t z){
    string selected = "[X] ";
    string notSelected = "[ ] ";
    if(isSelected) {
        
        setValue(selected + cbValue);
    } 
    else{ 
        setValue(notSelected + cbValue);
    }
    Label::draw(g,left,top,z);
}