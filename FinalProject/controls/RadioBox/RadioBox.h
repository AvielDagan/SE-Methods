#pragma once

#include "CheckList.h"
#include "CheckBox.h"

class RadioBox:public CheckList
{
private:
    
public:
    bool addSelectedItem(CheckBox cb);
    RadioBox();
    ~RadioBox();
};
