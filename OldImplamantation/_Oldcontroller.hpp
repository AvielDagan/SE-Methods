#include <windows.h>
#include <stdio.h>
#include "defindes.h"

class Controller
{
private:
    // HANDLE hStdin;
    COORD currCord;

public:
    Controller(COORD currCord) : currCord(currCord){}

    COORD getCurrCord() { return this->currCord; }
    void setCurrCord(COORD cord) { this->currCord = cord; }

};
