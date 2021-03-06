#pragma once
#include "vector"
#include "../../Common/Control/Control.hpp"
#include "../BorderDrawer/BorderDrawer.hpp"

using namespace std;

class Panel : public Control {
    public:
        Panel(short left, short top, BorderDrawer* border, Color textColor, Color backgroundColor);
        ~Panel();

        bool addControl(Control* control);
        Control* getControl(int index);
        int getFocusIndex();
        void cleanVec();

        virtual void draw(Graphics& g, int x, int y, size_t z);

		virtual void keyDown(int keyCode, char charecter);
		virtual void getAllControls(vector<Control*>* controls);

    protected:
        vector<Control*> controls;
        int focusIndex;

        void calculateWidthAndHeight();
};