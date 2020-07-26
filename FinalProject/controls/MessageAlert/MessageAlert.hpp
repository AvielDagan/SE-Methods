#pragma once

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.hpp"
// #include "../../Common/Control/Control.hpp"
#include "../SingleBorderDrawer/SingleBorderDrawer.hpp"
//need to call it in different name... it seemes MessageAlert already defined
class MessageAlert : public Panel
{
private:
    Label message;
    Button ok;
    Button cancel;
    string returnValue;
    Button *showButton;
    // Panel panel;
    bool show;

public:
    string getMessage();
    void setMessage(string message);
    string getReturnValue() { return returnValue; };
    void setShowButton(Button *button);

    virtual void draw(Graphics &g, int x, int y, size_t z);
    MessageAlert(short left, short top, short width,BorderDrawer* buttonBorder, BorderDrawer* border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button* showButton);
    ~MessageAlert() {}
};
