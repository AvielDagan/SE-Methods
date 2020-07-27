#include "CheckList.hpp"
#include "../SingleBorderDrawer/SingleBorderDrawer.hpp"

CheckList::CheckList(short left, short top, short width, BorderDrawer *border, Color textColor, Color backgroundColor,string labelText)
    : Panel(left, top, border, textColor, backgroundColor), marginTop(top + 4), curr(-1), message(left, top, width, border, textColor, backgroundColor,labelText)
{
    // focusIndex = -1;
}

// CheckList::~CheckList()
// {
//     for (int i = 0; i < items.size(); ++i)
//     {
//         delete items[i];
//     }
// }

void CheckList::addToList(string item)
{
    CheckBox *newItem = new CheckBox(left, this->marginTop, 10, new SingleBorderDrawer(), Color::Cyan, Color::Black, item, this);
    newItem->setCanClick(false);
    Panel::addControl(newItem);
    this->marginTop += 3;
    // newItem->addListener(this);
    // newItem->setSelectedString("[X] ");
    // newItem->setUnselectedString("[ ] ");
    // items.push_back(newItem);
    // Control::setHeight(Control::getHeight() + 3);
}

void CheckList::keyDown(int keyCode, char character)
{
    CheckBox *temp;

    int size = Panel::controls.size();
    // temp->setTextColor(Color::Red);
    // temp->setBackgroundColor(Color::White);
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
        temp = dynamic_cast<CheckBox *>(Panel::controls[curr]);
        if (curr == -1)
            ++curr;

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

// void CheckList::getSelectedItems(vector<string> &selected)
// {
//     for (int i = 0; i < selectedItems.size(); ++i)
//     {
//         selected.push_back(selectedItems[i]);
//     }
// }

// void CheckList::invertColors(CheckBox *item)
// {
//     Color tempColor = item->getTextColor();
//     item->setTextColor(item->getBackgroundColor());
//     item->setBackgroundColor(tempColor);
// }

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

// void CheckList::keyDown(int keyCode, char charecter)
// {
//     if (getFocusIndex() != -1)
//     {
//         if (keyCode == VK_RETURN || keyCode == VK_SPACE)
//         {
//             if (items[focusIndex]->getSelected() == true)
//             {
//                 items[focusIndex]->setSelected(false);
//                 removeSelectedItem(items[focusIndex]->getValue());
//             }
//             else
//             {
//                 items[focusIndex]->setSelected(true);
//                 addSelectedItem(items[focusIndex]->getValue());
//             }
//             return;
//         }
//         if (keyCode == VK_UP || keyCode == VK_NUMPAD8)
//         {
//             if (focusIndex == 0)
//             {
//                 focusIndex = items.size() - 1;
//             }
//             else
//             {
//                 --focusIndex;
//             }
//             Control::setFocus(*items[focusIndex]);
//             return;
//         }
//         if (keyCode == VK_DOWN || keyCode == VK_NUMPAD2)
//         {
//             if (focusIndex == items.size() - 1)
//             {
//                 focusIndex = 0;
//             }
//             else
//             {
//                 ++focusIndex;
//             }
//             Control::setFocus(*items[focusIndex]);
//             return;
//         }
//     }
// }

// void CheckList::getAllControls(vector<Control *> *controls)
// {
//     for (int i = 0; i < items.size(); ++i)
//     {
//         controls->push_back(items[i]);
//     }
// }

// int CheckList::getFocusIndex()
// {
//     Control *tempPtr = getFocus();
//     for (int i = 0; i < items.size(); ++i)
//     {
//         if (items[i] == tempPtr)
//         {
//             focusIndex = i;
//             return i;
//         }
//     }
//     focusIndex = -1;
//     return -1;
// }

// void CheckList::update(int x, int y, string s)
// {
//     for (int i = 0; i < items.size(); ++i)
//     {
//         if (s.compare(items[i]->getValue()) == 0)
//         {
//             if (items[i]->getSelected() == true)
//             {
//                 items[i]->setSelected(false);
//                 removeSelectedItem(items[i]->getValue());
//             }
//             else
//             {
//                 items[i]->setSelected(true);
//                 addSelectedItem(items[i]->getValue());
//             }
//             focusIndex = i;
//             Control::setFocus(*items[i]);
//             return;
//         }
//     }
// }
