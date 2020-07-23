#pragma once

#include <string>
#include "Label.h"

class TextBox : public Label
{
private:
    string input;

public:
    string getInputValue();
    void setInputValue(string);
    void getInputFromKB(string); //is needed?
    TextBox();
    ~TextBox();
};