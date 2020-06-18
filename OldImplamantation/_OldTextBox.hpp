#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "defindes.hpp"

using namespace std;

class TextBox
{
    string value; //name of the label
    COORD coord;  //coordinates
    DWORD colors; //colors
    HANDLE outHandle;

public:
    TextBox(COORD coord) : coord(coord){};

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

    void drawInputArea()
    {
        outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(outHandle, coord);
        SetConsoleTextAttribute(outHandle, this->colors);
        cout << "                   ";
    }

    void drawInput(int currYCord)
    {
        outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(outHandle, {OFFEST_LABLES_INPUT, currYCord});
        SetConsoleTextAttribute(outHandle, colors);
        CONSOLE_CURSOR_INFO info = {OFFEST_LABLES_INPUT, 1};
        SetConsoleCursorInfo(outHandle, &info);

        getline(cin, this->value);

        info = {OFFEST_LABLES_INPUT, 0};
        SetConsoleCursorInfo(outHandle, &info);
        return;
    }
};