#pragma once
#include <vector>
#include "../CheckBox/CheckBox.hpp"
#include "../../controls/Panel/Panel.hpp"

class CheckList : public Control {
    public:
        CheckList(short left, short top, short width, BorderDrawer* border, Color textColor, Color backgroundColor);
        ~CheckList();

        virtual void addToList(string item);
        bool addSelectedItem(string item);
        bool removeSelectedItem(string item);
        void getSelectedItems(vector<string>& selected);
        void invertColors(CheckBox* item);

        virtual void draw(Graphics& g, int x, int y, size_t z);
		virtual void keyDown(int keyCode, char charecter);
		virtual void getAllControls(vector<Control*>* controls);
		virtual bool canGetFocus() { return true; };
		virtual int getFocusIndex();
        virtual void update(int x, int y, string s);

    protected:
        vector<CheckBox*> items;
        vector<string> selectedItems;
        int focusIndex;
};
