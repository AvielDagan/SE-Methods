#include <string>
#include <windows.h>
#include <iostream>
#include "defindes.hpp"

using namespace std;

class Label
{
    string value; //name of the label
    COORD coord;  //coordinates
    DWORD colors;
    HANDLE outHandle;

public:
    Label(){};
    Label(string value, COORD coord) : value(value), coord(coord){};

    void setValue(string value) { this->value = value; }
    string getValue() { return this->value; }

    void setCoord(COORD coord) { this->coord = coord; }
    COORD getCoord() { return this->coord; }

    void setOutHandle(HANDLE nOutHandle) { this->outHandle = nOutHandle; }
    HANDLE getOutHandle() { return this->outHandle; }

    void setColors(DWORD fg = 0, DWORD bg = 0)
    {
        this->colors = fg | bg;
    }

    void draw()
    {
        /**
         * 1. Set console cordinated //
         * 2. Write text to console // cout << ...
         * 3. Hide input cursor
         */

        outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(this->getOutHandle(), coord);
        SetConsoleTextAttribute(this->getOutHandle(), colors);
        cout << this->value;
    }
};