#pragma once
#include <string>
#include "Control.hpp"
#include "Subject.hpp"

using namespace std;

class Label : public Control, public Subject
{
private:
    string title;

public:
    string getTitle();
    void setTitle(string);
    void draw(Graphics &g, int x, int y, size_t z); //inherits from Control

    Label(short left, short top, short width, string value);
    Label();
    ~Label();
};