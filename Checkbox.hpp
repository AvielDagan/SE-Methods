#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

class Checkbox
{
    Label label;
    boolean isChecked;
    COORD coord;  //coordinates
    DWORD colors; //colors
    HANDLE outHandle;

public:
    Checkbox(COORD coord) : isChecked(true), coord(coord){};

    // Checkbox(Label label, COORD coord) : label(label),
    //                                      coord(coord),
    //                                      isChecked(true){};

    void setLabel(Label label) { this->label = label; }
    Label getLabel() { return this->label; }

    void setCoord(COORD coord) { this->coord = coord; }
    COORD getCoord() { return this->coord; }

    void setOutHandle(HANDLE nOutHandle) { this->outHandle = nOutHandle; }
    HANDLE getOutHandle() { return this->outHandle; }

    void setColors(DWORD fg = 0, DWORD bg = 0)
    {
        this->colors = fg | bg;
    }

    void setCheckedBox()
    {
        isChecked = !isChecked;
    }

    void drawLabel()
    {
        this->getLabel().draw();
    }

    void drawBoxArea()
    {
        outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(outHandle, coord);
        SetConsoleTextAttribute(outHandle, this->colors);
        this->isChecked ? cout << " X " : cout << "   ";
    }

    void drawOnPress(int currYCord)
    {
        outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(outHandle, {OFFEST_LABLES_INPUT, currYCord});
        SetConsoleTextAttribute(outHandle, colors);
        CONSOLE_CURSOR_INFO info = {OFFEST_LABLES_INPUT, 0};
        SetConsoleCursorInfo(outHandle, &info);
    }
};