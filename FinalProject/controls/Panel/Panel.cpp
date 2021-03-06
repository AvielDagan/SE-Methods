#include "./Panel.hpp"

Panel::Panel(short left, short top, BorderDrawer* border, Color textColor, Color backgroundColor) :
    Control(left, top, 15, 15, border, textColor, backgroundColor) {
        calculateWidthAndHeight();
}

Panel::~Panel() {
    for(auto *val : controls) {
        delete val;
    }
    if(border)
        delete border;
}

bool Panel::addControl(Control* control) {
    if(control != nullptr) {
        try {
            controls.push_back(control);
            if(getFocus() == nullptr && control->canGetFocus()) {
                setFocus(*control);
            }
        }
        catch(...) {
            return false;
        }
        return true;
    }
    return false;
}

Control* Panel::getControl(int index) {
    if(controls.size() < index || index < 0) {
        return nullptr;
    }
    return controls[index];
}

int Panel::getFocusIndex() {
    Control* tempPtr = getFocus();
    for(int i = 0; i < controls.size(); ++i) {
        if(controls[i] == tempPtr) {
            focusIndex = i;
            return i;
        }
        else if(controls[i]->getFocusIndex() != -1) {
            focusIndex = i;
            return i;
        }
    }
    focusIndex = -1;
    return -1;
}

void Panel::draw(Graphics& g, int x, int y, size_t z) {
    int relativeX, relativeY;
    calculateWidthAndHeight();
    if(z == 0 && this->getShow()) {
        Control::draw(g, x, y, z);
        for(int i = 0; i < controls.size(); ++i) {
            relativeX = controls[i]->getLeft();
            relativeY = controls[i]->getTop();
            g.setForeground(controls[i]->getTextColor());
            g.setBackground(controls[i]->getBackgroundColor());
            controls[i]->draw(g, x + relativeX + 1, y + relativeY + 1, z);
        }
    }
    if(z == 1 && this->getShow()) {
        if(getFocusIndex() != -1) {
            relativeX = controls[focusIndex]->getLeft();
            relativeY = controls[focusIndex]->getTop();
            g.setForeground(controls[focusIndex]->getTextColor());
            g.setBackground(controls[focusIndex]->getBackgroundColor());
            controls[focusIndex]->draw(g, x + relativeX + 1, y + relativeY + 1, 0);
        }
    }
}



void Panel::keyDown(int keyCode, char charecter) {
    if(getFocusIndex() != -1) {
        controls[focusIndex]->keyDown(keyCode, charecter);
    }
}

void Panel::getAllControls(vector<Control*>* controls) {
    for(int i = 0; i < this->controls.size(); ++i) {
        controls->push_back(this->controls[i]);
        this->controls[i]->getAllControls(controls);
    }
}

void Panel::calculateWidthAndHeight() {
    short calcWidth = 0, calcHeight = 0, ciLeft, ciTop, ciWidth, ciHeight;
    for(int i = 0; i < controls.size(); ++i) {
        ciLeft = controls[i]->getLeft();
        ciTop = controls[i]->getTop();
        ciWidth = controls[i]->getWidth();
        ciHeight = controls[i]->getHeight();
        if(ciLeft + ciWidth > calcWidth) {
            calcWidth = ciLeft + ciWidth;
        }
        if(ciTop + ciHeight > calcHeight) {
            calcHeight = ciTop + ciHeight;
        }
    }
    setWidth(calcWidth + 5);
    setHeight(calcHeight + 5);
}

void Panel::cleanVec() {
    controls.clear();
}