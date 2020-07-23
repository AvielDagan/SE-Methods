#pragma once

#include "../../Common/Graphics/Graphics.hpp"
#include "iostream"
using namespace std;

class BorderDrawer
{
public:
	// BorderDrawer(char topLeft, char topRight, char bottomLeft, char bottomRight, char horizontal, char vertical) :
    // topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight), horizontal(horizontal),
    // vertical(vertical) {} ;
	// void draw(Graphics& g,short left, short top, short width, short height){}//need to finish this method
	// virtual void drawBorder(Graphics &g, short left, short top, int width, int height)
	// {
	// 	string line(width, horizontal);
	// 	string space(width, ' ');
	// 	g.moveTo(left, top);
	// 	cout << topLeft << line << topRight;
	// 	for (int i = 1; i < height - 1; ++i)
	// 	{
	// 		g.moveTo(left, top + i);
	// 		cout << vertical << space << vertical;
	// 	}
	// 	g.moveTo(left, top + height - 1);
	// 	cout << bottomLeft << line << bottomRight;
	// };
	// virtual ~BorderDrawer() = 0;


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



