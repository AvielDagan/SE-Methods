#pragma once

#include "../Panel/Panel.hpp"
#include "../Label/Label.hpp"
#include "../Button/Button.hpp"
#include "../SingleBorderDrawer/SingleBorderDrawer.hpp"

class MessageAlert : public Panel
{
private:
    Label message;
    Button okBtn;
    Button cancel;
    string returnValue;
    Button *showButton;
    bool show;

public:
    string getMessage();
    void setMessage(string message);
    string getReturnValue() { return returnValue; };
    void setShowButton(Button *button);
    void notify(string text);

    virtual void draw(Graphics &g, int x, int y, size_t z);
    MessageAlert(short left, short top, short width, BorderDrawer *buttonBorder, BorderDrawer *border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button *showButton);
    ~MessageAlert() {}
};
