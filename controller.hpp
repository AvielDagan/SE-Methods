#include <windows.h>
#include <stdio.h>
#include "defindes.hpp"

class Controller
{
private:
    // HANDLE hStdin;
    COORD currCord;

public:
    Controller(COORD currCord) : currCord(currCord)
    {
        // hStdin = GetStdHandle(STD_INPUT_HANDLE);
    };

    COORD getCurrCord() { return this->currCord; }
    void setCurrCord(COORD cord) { this->currCord = cord; }

    // HANDLE gethStdin() { return this->hStdin; }
};
