#pragma once

#include "../Graphics/Graphics.hpp"
#include "iostream"
using namespace std;

class BorderDrawer
{
public:
	BorderDrawer(char topLeft, char topRight, char bottomLeft, char bottomRight, char horizontal, char vertical) :
    topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight), horizontal(horizontal),
    vertical(vertical) {} ;

	virtual void draw(Graphics &g, short left, short top, int width, int height)
	{
		string line(width, horizontal);
		string space(width, ' ');
		g.moveTo(left, top);
		cout << topLeft << line << topRight;
		for (int i = 1; i < height - 1; ++i)
		{
			g.moveTo(left, top + i);
			cout << vertical << space << vertical;
		}
		g.moveTo(left, top + height - 1);
		cout << bottomLeft << line << bottomRight;
	};
	virtual ~BorderDrawer() = 0;

protected:
	char topLeft;
	char topRight;
	char bottomLeft;
	char bottomRight;
	char horizontal;
	char vertical;
};



