#include "./CheckList.hpp"

CheckList::CheckList(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor, size_t layer) 
: Panel(left, top, border, textColor, BgColor, layer)
{
}
CheckList::~CheckList()
{
}

bool CheckList::addItemToList(CheckBox)
{
}
bool CheckList::removeItemFromList(CheckBox)
{
}
bool CheckList::addSelectedItem(CheckBox)
{
}
bool CheckList::removeSelectedItem(CheckBox)
{
}
vector<CheckBox> CheckList::getSelectedCheckBoxes()
{
}