#pragma once

#include "../../Common/Graphics/Graphics.hpp"
#include "iostream"
using namespace std;

class BorderDrawer
{
public:
        BorderDrawer(char topLeft, char topRight, char bottomLeft, char bottomRight, char horizontal, char vertical);
        virtual ~BorderDrawer() = 0;
        virtual void drawBorder(Graphics& g, short left, short top, short width, short height);
protected:
	char topLeft;
	char topRight;
	char bottomLeft;
	char bottomRight;
	char horizontal;
	char vertical;
};



