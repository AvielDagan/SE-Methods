#pragma once

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"


//need to call it in different name... it seemes MessageBox already defined
class MessageBox : public Panel
{
private:
    Button cancel;
    Button ok;
    Label text;

public:
    //?
    MessageBox();
    ~MessageBox();
};
