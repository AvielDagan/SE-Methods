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
    bool addItemToList(CheckBox& cb);
    bool removeItemFromList(CheckBox& cb);
    bool addSelectedItem(CheckBox& cb);
    bool removeSelectedItem(CheckBox& cb);
    vector<CheckBox> getSelectedCheckBoxes();
    CheckList(short left,short top,short width, short height, BorderDrawer* border, Color textColor, Color BgColor, size_t layer);
    ~CheckList();
};

