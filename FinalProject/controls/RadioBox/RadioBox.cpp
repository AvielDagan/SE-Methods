#include "./RadioBox.hpp"

RadioBox::RadioBox(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor, string labelText)
    : CheckList(left, top, width, border, textColor, backgroundColor, labelText)
{
}

void RadioBox::keyDown(int keyCode, char character)
{
    CheckBox *temp;

    int size = Panel::controls.size();

    if (keyCode == VK_UP)
    {
        if (curr == 0)
        {
            curr = size - 1;
        }
        else
        {
            --curr;
        }

        for (auto &value : Panel::controls)
        {
            value->setTextColor(textColor);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);
        temp->setTextColor(Color::White);
    }
    if (keyCode == VK_SPACE)
    {

        if (curr == -1)
            ++curr;
        for (int i = 0; i < Panel::controls.size(); ++i)
        {
            temp = dynamic_cast<CheckBox *>(Panel::controls[i]);
            if(temp->getIsSelected()){
                temp->selectBox();
                removeSelectedItem(temp->getValue());
            }
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);

        temp->selectBox();

        if (temp->getIsSelected())
        {
            addSelectedItem(temp->getValue());
        }
        else
        {
            removeSelectedItem(temp->getValue());
        }
    }
    if (keyCode == VK_DOWN)
    {
        if (curr == size - 1)
        {
            curr = 0;
        }
        else
        {
            ++curr;
        }

        for (auto &value : Panel::controls)
        {
            value->setTextColor(textColor);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);
        temp->setTextColor(Color::White);
    }
}
