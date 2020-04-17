#pragma once
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

public:
    Label(){};
    Label(string value, COORD coord) : value(value), coord(coord){};

    // Label(string value, COORD coord) : value(value), coord(coord){};
    void setValue(string value) { this->value = value; }
    string getValue() { return this->value; }

    void setCoord(COORD coord) { this->coord = coord; }
    COORD getCoord() { return this->coord; }

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

        auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(outHandle, coord);
        SetConsoleTextAttribute(outHandle, colors);
        cout << this->value;

        CONSOLE_CURSOR_INFO info = {20, 0};
        SetConsoleCursorInfo(outHandle, &info);
    }
};