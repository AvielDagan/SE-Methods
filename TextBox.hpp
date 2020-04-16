#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

class TextBox
{
    string value; //name of the label
    COORD coord;  //coordinates
    DWORD colors; //colors
    HANDLE outHandle;

public:
    TextBox(string value, COORD coord) : value(value), coord(coord), outHandle(GetStdHandle(STD_OUTPUT_HANDLE)){};

    void setValue(string value) { this->value = value; }
    string getValue() { return this->value; }

    void setCoord(COORD coord) { this->coord = coord; }
    COORD getCoord() { return this->coord; }

    void setOutHandle(HANDLE nOutHandle) {this->outHandle = nOutHandle;}
    HANDLE getOutHandle() { return this->outHandle; }

    void setColors(DWORD fg, DWORD bg)
    {
        this->colors = fg | bg;
    }

    void draw()
    {
        SetConsoleCursorPosition(this->getOutHandle(), coord);
        SetConsoleTextAttribute(this->getOutHandle(), colors);
        cout << this->value;

        SetConsoleCursorPosition(this->getOutHandle(), {15,3});
        SetConsoleTextAttribute(this->getOutHandle(), colors);
        cout << "          ";
        SetConsoleCursorPosition(this->getOutHandle(), {15,3});

        cin  >> this->value;
        
        CONSOLE_CURSOR_INFO info = {20, 1};
        SetConsoleCursorInfo(outHandle, &info);
    }
};
