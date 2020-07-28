#include "CheckList.hpp"
#include "../SingleBorderDrawer/SingleBorderDrawer.hpp"

CheckList::CheckList(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor,string labelText)
    : Panel(left, top, border, textColor, backgroundColor), marginTop(top + 4), curr(-1), message(left, top, width, border, textColor, backgroundColor,labelText){}

void CheckList::addToList(string item)
{
    CheckBox *newItem = new CheckBox(left, this->marginTop, 10, new SingleBorderDrawer(), Color::Cyan, Color::Black, item, this);
    newItem->setCanClick(false);
    Panel::addControl(newItem);
    this->marginTop += 3;


}
CheckList::~CheckList() {
    if(border)
        delete border;
}

void CheckList::keyDown(int keyCode, char character)
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
            value->setTextColor(Color::White);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);
        temp->setTextColor(Color::Red);
    }
    if (keyCode == VK_SPACE)
    {
        if (curr == -1)
            ++curr;
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);

        temp->selectBox();

        if(temp->getIsSelected()) {
            addSelectedItem(temp->getValue());
        } else{
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
            value->setTextColor(Color::White);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);
        temp->setTextColor(Color::Red);
    }
}
bool CheckList::addSelectedItem(string item)
{
    for (int i = 0; i < selectedBoxes.size(); ++i)
    {
        if (item.compare(selectedBoxes[i]) == 0)
        {
            return false;
        }
    }
    selectedBoxes.push_back(item);
    return true;
}

bool CheckList::removeSelectedItem(string item)
{
    for (int i = 0; i < selectedBoxes.size(); ++i)
    {
        if (item.compare(selectedBoxes[i]) == 0)
        {
            selectedBoxes.erase(selectedBoxes.begin() + i);
            return true;
        }
    }
    return false;
}


void CheckList::draw(Graphics &g, int x, int y, size_t z)
{
    if (Control::getFocus() == this)
    {
        message.draw(g,x,y,z);
    }
    for (auto &value : Panel::controls)
    {
        value->draw(g, value->getLeft(), value->getTop(), z);
    }
}
