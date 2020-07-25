#pragma once

#include <vector>
#include "../Graphics/Graphics.hpp"
#include "../../controls/BorderDrawer/BorderDrawer.hpp"
#include "../../controls/Observer/Observer.hpp"

using namespace std;

class Control : public Observer
{
protected:
	short _left;
	short _top;
	short _width;
	short _height;
	BorderDrawer *_border;
	Color _textColor;
	Color _BgColor;
	size_t _layer;
	static Control *_focused;

public:
	//static and virtual  implemented in the hpp file

	virtual bool canGetFocus() { return false; };

	static Control *getFocus() { return _focused; };
	virtual short getLeft() { return _left; };
	virtual short getTop() { return _top; };
	virtual short getWidth() { return _width; };
	virtual short getHeight() { return _height; };
	BorderDrawer *getBorder() { return _border; };
	Color getTextColor() { return _textColor; };
	Color getBgColor() { return _BgColor; };
	virtual int getFocusIndex() { return -1; };

	static void setFocus(Control &control) { _focused = &control; };
	virtual void setLeft(short left) { this->_left = left; };
	virtual void setTop(short top) { this->_top = top; };
	virtual void setWidth(short width) { this->_width = width; };
	virtual void setHeight(short height) { this->_height = height; };
	void setBorderDrawer(BorderDrawer &borderDrawer) { _border = &borderDrawer; }
	void setTextColor(Color textColor) { this->_textColor = textColor; };
	void setBgColor(Color BgColor) { this->_BgColor = BgColor; };

	virtual void draw(Graphics &g, short left, short top, size_t layer);
	virtual void keyDown(int keyCode, char charecter){};
	virtual void getAllControls(vector<Control *> *controls){};

	// virtual void draw(Graphics &g, int x, int y, size_t z){};

	Control(short left, short top, short width, short height, BorderDrawer *border, Color textColor, Color BgColor);
	virtual ~Control() = 0;
};
