#include "ComboBox.hpp"
#include "../SingleBorderDrawer/SingleBorderDrawer.hpp"
#include <iostream>
using namespace std;

ComboBox::ComboBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor) : Panel(left + 5, top + 5, border, textColor, backgroundColor),
                                                                                                                       // showButton(left + 15, top + 1, 1, new SingleBorderDrawer(), textColor, backgroundColor, " +",this),
                                                                                                                       text(left + 1, top + 1, 10, new SingleBorderDrawer(), textColor, backgroundColor, ""),
                                                                                                                       curr(0),
                                                                                                                       marginTop(top + 5),
                                                                                                                       optionsIsOpen(false)

{
    // this->setShow(false);
}

void ComboBox::addToList(string toAdd)
{
    Button *newButton = new Button(left - 3, this->marginTop, 10, new SingleBorderDrawer(), textColor, backgroundColor, toAdd, this);
    newButton->setShow(false);
    newButton->setCanClick(false);
    Panel::addControl(newButton);
    this->marginTop += 3;
}

void ComboBox::notify(string s)
{
    if (s.compare(" +") == 0)
    {
        if (this->optionsIsOpen)
        {
            this->optionsIsOpen = !this->optionsIsOpen;
            this->setShow(false);
            for (auto &value : Panel::controls)
            {
                value->setShow(false);
                Button *temp = dynamic_cast<Button *>(value);
                // temp->setCanClick(false);
            }
        }
        else
        {
            this->setShow(true);

            this->optionsIsOpen = !this->optionsIsOpen;
            for (auto &value : Panel::controls)
            {
                value->setShow(true);
                Button *temp = dynamic_cast<Button *>(value);
                // temp->setCanClick(true);
            }
        }
    }
    else
    {

        this->text.setValue(s);
        this->optionsIsOpen = !this->optionsIsOpen;
        this->setShow(false);
        for (auto &value : Panel::controls)
        {
            value->setShow(false);
            Button *temp = dynamic_cast<Button *>(value);
            // temp->setCanClick(false);
        }
    }

    return;
}

void ComboBox::draw(Graphics &g, int x, int y, size_t z)
{
    if (z == 0)
    {
        if (this->getShow())
        {
            for (auto &value : Panel::controls)
            {
                value->draw(g, value->getLeft(), value->getTop(), z);
                this->marginTop += 3;
            }
        }
        text.draw(g, text.getLeft() + 1, text.getTop() + 1, z);
    }
}

void ComboBox::keyDown(int keyCode, char character)
{
    Button *temp = dynamic_cast<Button *>(Panel::controls[curr]);
    for (auto &value : Panel::controls)
        {
            value->setTextColor(Color::White);
            // temp->setBackgroundColor(Color::Blue);

            
        }
    int size = Panel::controls.size();
    temp->setTextColor(Color::Red);
    // temp->setBackgroundColor(Color::White);
    if (keyCode == VK_UP)
    {   
        curr--;
    }
    if (keyCode == VK_SPACE)
    {
        this->text.setValue(temp->getValue());
        this->optionsIsOpen = !this->optionsIsOpen;
        this->setShow(false);
        for (auto &value : Panel::controls)
        {
            value->setShow(false);
            
        }
    }
    if(keyCode == VK_DOWN){
        curr++;
    }

    //   if(keyCode == VK_UP || keyCode == VK_NUMPAD8){
    //             if(focusIndex == 0) {
    //                 focusIndex = items.size() - 1;
    //             }
    //             else {
    //                 --focusIndex;
    //             }
    //             Control::setFocus(*items[focusIndex]);
    //             return;
    //         }
    //         if(keyCode == VK_DOWN || keyCode == VK_NUMPAD2){
    //             if(focusIndex == items.size() - 1) {
    //                 focusIndex = 0;
    //             }
    //             else {
    //                 ++focusIndex;
    //             }
    //             Control::setFocus(*items[focusIndex]);
    //             return;
    //         }

    // Color tempColor;
    // if(show){
    //     if(keyCode == VK_RETURN || keyCode == VK_SPACE){
    //         text.setValue(list[curr]->getValue());
    //         show = false;
    //         showButton.setValue(" +");
    //         invertColor(list[curr]);
    //         curr = 0;
    //         return;
    //     }

    //     if(keyCode == VK_UP || keyCode == VK_NUMPAD8){
    //         if(curr == 0)
    //             return;

    //         invertColor(list[curr]);
    //         --curr;
    //         invertColor(list[curr]);
    //         return;
    //     }

    //     if(keyCode == VK_DOWN || keyCode == VK_NUMPAD2){
    //         if(curr + 1 == list.size())
    //             return;

    //         invertColor(list[curr]);
    //         ++curr;
    //         invertColor(list[curr]);
    //         return;
    //     }
    // }
    // return;
}