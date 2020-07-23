#pragma once

#include <vector>
#include "Graphics.h"
#include "../BorderDrawer/BorderDrawer.h"
#include "../Observer/Observer.h"

using namespace std;


class Control : public Observer
{
private: 
	const BorderDrawer *_borderDrawer;

protected:
	short _left;
	short _top;
public:
	//static and virtual  implemented in the hpp file
	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	
	
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return 0; };
	virtual short getTop() { return 0; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };

	virtual void setBorderDrawer(const BorderDrawer &borderDrawer) { _borderDrawer = &borderDrawer; }
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void draw(Graphics &g, short left, short top,int width,int height, size_t layer) const {
		_borderDrawer->draw(g, _left + left, _top + top, width, height);
	}

	Control(){}
	~Control(){}
};

