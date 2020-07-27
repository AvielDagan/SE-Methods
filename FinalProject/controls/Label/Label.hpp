#pragma once
#include "../../Common/Control/Control.hpp"
#include "../Subject/Subject.hpp"
#include <string>


using namespace std;

class Label: public Control, public Subject
{   
    protected:
        string value;
    public:
        Label(short left, short top, short width, BorderDrawer* border, Color textColor, Color backgroundColor, string value);
        string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
};