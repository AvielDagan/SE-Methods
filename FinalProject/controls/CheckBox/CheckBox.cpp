
#include "./CheckBox.hpp"

CheckBox::CheckBox(short left, short top, short width,BorderDrawer* buttonBorder, Color textColor, Color backgroundColor, string value):
    Button(left, top, width, buttonBorder, textColor, backgroundColor, value)
{
    selected = false;
    selectedString = "";
    unselectedString = "";
}

CheckBox::~CheckBox()
{
    delete this;
}


void CheckBox::draw(Graphics& g, int x, int y, size_t z) {
    if(z == 0) {
        Button::draw(g, x, y, z);
        if(selected == true) {
            g.write(x + 1, y + 1, selectedString);
        }
        else {
            g.write(x + 1, y + 1, unselectedString);
        }
        // g.write(x + 5, y + 1, getValue());
    }
}

void CheckBox::keyDown(int keyCode, char charecter) {
    // dynamic_cast<Control*>(listeners[0])->keyDown(keyCode, charecter);
}