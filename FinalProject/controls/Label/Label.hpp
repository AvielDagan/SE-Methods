#pragma once
#include <string>
#include "../../Common/Control/Control.hpp"
#include "../Subject/Subject.hpp"

using namespace std;

class Label : public Control, public Subject
{
private:
    string title;

public:
    string getTitle();
    void setTitle(string s);
    void draw(Graphics &g, short left, short top, short width, short height, size_t z); //inherits from Control


    Label(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor, string value);
    // ~Label();
};