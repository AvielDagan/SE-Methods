#include <windows.h>
#include "Label.h"

int main(int argc,char const* argv[]){
    Label label("Hello world",{5,5});
    label.setColors(FOREGROUND_GREEN | FOREGROUND_INTENSITY , BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    label.draw();
    while(1);
    return 0;
}