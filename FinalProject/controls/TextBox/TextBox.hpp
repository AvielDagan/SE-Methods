#pragma once

#include <string>
#include "Label.hpp"

class TextBox : public Label
{
private:
    string input;

public:
    COORD currentCoord;
    string getInputValue();
    void setInputValue(string);
    void getInputFromKB(string); //is needed?
    TextBox();
    ~TextBox();
};