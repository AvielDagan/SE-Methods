#pragma once
#include "./Button.hpp"
#include <iostream>
using namespace std;
#include "../Label/Label.h"

Button::Button(short left, short top, short width, BorderDrawer* border, Color textColor, Color BgColor,string title)
 : Label(left,top,width,border,textColor,BgColor,title){}

// Button::~Button()
// {
// }

  void Button::keyDown(int keyCode, char character) {
       if(keyCode == VK_SPACE){
           cout << "keyDown!" << endl;
            return;
        }
  }