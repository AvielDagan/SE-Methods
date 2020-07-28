#pragma once
#include <vector>
#include <typeinfo>
#include "../Graphics/Graphics.hpp"
#include "../../Controls/BorderDrawer/BorderDrawer.hpp"
#include "../../controls/Observer/Observer.hpp"
#include <string>

using namespace std;

class Control : public Observer
{
public:
	Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color backgroundColor);
	virtual ~Control() = 0;

	static Control *getFocus() { return focusedControl; };
	static void setFocus(Control &control);


	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual short getWidth() { return width; };
	virtual short getHeight() { return height; };
	bool getShow() {return show;};
	BorderDrawer *getBorder() { return border; };
	Color getTextColor() { return textColor; };
	Color getBackgroundColor() { return backgroundColor; };

	virtual void setLeft(short left) { this->left = left; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setWidth(short width) { this->width = width; };
	virtual void setHeight(short height) { this->height = height; };
	void setBorder(BorderDrawer *border);
	void setTextColor(Color textColor) { this->textColor = textColor; };
	void setBackgroundColor(Color backgroundColor) { this->backgroundColor = backgroundColor; };
	void setShow(bool f);

	virtual void draw(Graphics &g, int x, int y, size_t z);
	virtual void keyDown(int keyCode, char charecter){};
	virtual void getAllControls(vector<Control *> *controls){};
	virtual bool canGetFocus() { return false; };
	virtual int getFocusIndex() { return -1; };

protected:
	static Control *focusedControl;

	short left;
	short top;
	short width;
	short height;
	BorderDrawer *border;
	Color textColor;
	Color backgroundColor;
	bool show;
};
