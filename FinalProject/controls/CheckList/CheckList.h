#pragma once

#include <vector>
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../CheckBox/CheckBox.h"

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
    CheckList(/* args */);
    ~CheckList();
};

