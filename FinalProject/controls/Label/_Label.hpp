#pragma once
#include <string>
#include "../../Common/Control/Control.h"
#include "../Subject/Subject.hpp"

using namespace std;

class Label : public Control, public Subject
{
private:
    string title;

public:
    Label(short left, short top, short width,  BorderDrawer *border, Color textColor, Color BgColor, string value);
    string getTitle();
    void setTitle(string s);
    void draw(Graphics &g, short left, short top, size_t z); //inherits from Control


    // ~Label();
};