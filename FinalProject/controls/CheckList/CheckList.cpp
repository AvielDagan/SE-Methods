#include "./CheckList.hpp"

CheckList::CheckList(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor, size_t layer) 
: Panel(left, top, border, textColor, BgColor, layer)
{
}
CheckList::~CheckList()
{
    for(int i = 0; i < selectedItems.size(); ++i) {
        selectedItems.pop_back();
    }
}

bool CheckList::addItemToList(CheckBox& cb)
{
    cb.setSelectedString("[X] ");
    cb.setUnselectedString("[ ] ");
    selectedItems.push_back(cb);
    Control::setHeight(Control::getHeight() + 3);
    return true;
}
bool CheckList::removeItemFromList(CheckBox& cb)
{
    // selectedItems.pop_back(cb);
    return true;
}
bool CheckList::addSelectedItem(CheckBox& cb)
{
    //Check if already exist
    for(int i = 0; i < selectedItems.size(); ++i) {
        if(cb.getSelectedString().compare(selectedItems[i].getSelectedString()) == 0) {
            return false;
        }
    }
    selectedItems.push_back(cb);
    return true;
}
bool CheckList::removeSelectedItem(CheckBox& cb)
{
     for(int i = 0; i < selectedItems.size(); ++i) {
        if(cb.getSelectedString().compare(selectedItems[i].getSelectedString()) == 0) {
            selectedItems.erase(selectedItems.begin() + i);
            return true;
        }
    }
    return false;
}
vector<CheckBox> CheckList::getSelectedCheckBoxes()
{
     return selectedItems;
}