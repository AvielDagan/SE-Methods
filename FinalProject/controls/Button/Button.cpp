#pragma once
#include "./Button.hpp"
#include <iostream>
#include "../Label/Label.hpp"
using namespace std;

Button::Button(short left, short top, short width, BorderDrawer* border, Color textColor, Color BgColor,string title,Observer* observ)
 : Label(left,top,width,border,textColor,BgColor,title){
   Subject::addObserver(observ);
 }

// Button::~Button()
// {
// }

  void Button::keyDown(int keyCode, char character) {
       if(keyCode == VK_SPACE){
         actions(this->getValue());
        }
  }
