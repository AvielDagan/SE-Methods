#pragma once

#include "../Panel/Panel.hpp"
#include "../Label/Label.hpp"
#include "../Button/Button.hpp"


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
