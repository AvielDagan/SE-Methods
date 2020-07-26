#pragma once

#include <vector>
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../CheckBox/CheckBox.hpp"

using namespace std;

class CheckList : public Panel
{
private:
    vector<CheckBox> selectedItems;
public:
    bool addItemToList(CheckBox);
    bool removeItemFromList(CheckBox);
    bool addSelectedItem(CheckBox);
    bool removeSelectedItem(CheckBox);
    vector<CheckBox> getSelectedCheckBoxes();
    CheckList(short left,short top,short width, short height, BorderDrawer* border, Color textColor, Color BgColor, size_t layer);
    ~CheckList();
};

