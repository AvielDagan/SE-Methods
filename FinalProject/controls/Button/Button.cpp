#pragma once
#include "./Button.hpp"
#include <iostream>
#include "../Label/Label.hpp"
using namespace std;

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