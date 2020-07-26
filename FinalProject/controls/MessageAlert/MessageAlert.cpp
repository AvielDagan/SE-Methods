#include "MessageAlert.hpp"
#include <iostream>
using namespace std;
MessageAlert::MessageAlert(short left, short top, short width,BorderDrawer* buttonBorder, BorderDrawer* border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button* showButton) 
:   Panel(left + 5, top + 5, border, textColor, backgroundColor),
    message(Label((width - message.size()) / 2, 0, message.size(),buttonBorder, textColor, backgroundColor, message)),
    okBtn(Button(0, 4, ok.size(), buttonBorder, Color::White, Color::Green, ok,this)),
    cancel(Button(width - cancel.size() - 2, 4,5,  buttonBorder, Color::White, Color::Red, cancel,this)),
    showButton(showButton) 
    {
        // Panel:addControl(this);
        Panel::addControl(&this->message);
        Panel::addControl(&this->okBtn);
        Panel::addControl(&this->cancel);
        returnValue = "";
        show = true;
    }
    


string MessageAlert::getMessage() {
    return message.getValue();
}

void MessageAlert::setMessage(string message) {
    this->message.setValue(message);
}

void MessageAlert::setShowButton(Button *button) {
    this->showButton = button;
}

void MessageAlert::draw(Graphics& g, int x, int y, size_t z) {
    int relativeX, relativeY;
    // cout << "                                                                                                                                                                                   @!@!" << endl;
    if(z == 0 && this->show == true) {
        Panel::draw(g, x , y, z);
        relativeX = message.getLeft();
        relativeY = message.getTop();
        // cout << "                                                                                                                                                                                   @!@!" << endl;
        if(message.getShow()) 
            message.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = okBtn.getLeft();
        relativeY = okBtn.getTop();
        if(okBtn.getShow())
            okBtn.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = cancel.getLeft();
        relativeY = cancel.getTop();
        if(cancel.getShow())
            cancel.draw(g, x + relativeX + 1, y + relativeY + 1, z);
    }
}


void MessageAlert::notify(string text) {
    if(text == "OK") {
        cancel.setShow(false);
        cancel.setCanClick(false);
    }

    if(text == "CANCEL"){
        this->setShow(false);
        cancel.setShow(false);
        cancel.setCanClick(false);
        okBtn.setShow(false);
        okBtn.setCanClick(false);
        message.setShow(false);
    }
} 