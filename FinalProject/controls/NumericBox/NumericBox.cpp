#include "./NumericBox.hpp"

NumericBox::NumericBox(short left, short top, int maxVal, int minVal, BorderDrawer *border, Color textColor, Color backgroundColor) : Panel(left, top, border, textColor, backgroundColor),
                                                                                                                                      currVal(Label(left + 7, top + 2, 3, border, textColor, backgroundColor, " 0 ")),
                                                                                                                                      add(Button(left + 14, top + 2, 1, border, textColor, backgroundColor, " + ", this)),
                                                                                                                                      subtract(Button(left + 2, top + 2, 1, border, textColor, backgroundColor, " - ", this)),
                                                                                                                                      maxVal(maxVal),
                                                                                                                                      minVal(minVal),
                                                                                                                                      value(0)
{
    Panel::addControl(&this->add);
    Panel::addControl(&this->subtract);
    Panel::addControl(&this->currVal);
}

NumericBox::~NumericBox()
{
}
void NumericBox::increase()
{
    string strVal = " ";

    if (value < maxVal)
    {
        ++value;
        currVal.setValue(strVal + to_string(value));
    }
}
void NumericBox::decrease()
{
    string strVal = " ";

    if (value > minVal)
    {
        --value;
        currVal.setValue(strVal + to_string(value));
    }
}

int NumericBox::getVal()
{
    return value;
}

void NumericBox::setVal(int val)
{
    string strVal = " ";
    if (val > maxVal)
    {
        val = maxVal;
    }
    if (val < minVal)
    {
        val = minVal;
    }

    currVal.setValue(strVal + to_string(value));
}

int NumericBox::getMin()
{
    return minVal;
}
int NumericBox::setMin(int min)
{
    if (min > maxVal)
        return -1;

    minVal = min;
    return 0;
}
int NumericBox::getMax()
{
    return maxVal;
}
int NumericBox::setMax(int max)
{
    if (max < minVal)
        return -1;

    maxVal = max;
    return 0;
}
bool NumericBox::setValue(int val)
{
    value = val;
    return true;
}

void NumericBox::draw(Graphics &g, int x, int y, size_t z)
{
    short relativeX, relativeY;
    if (z == 0)
    {
        relativeX = currVal.getLeft();
        relativeY = currVal.getTop();
        currVal.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = add.getLeft();
        relativeY = add.getTop();
        add.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = subtract.getLeft();
        relativeY = subtract.getTop();
        subtract.draw(g, relativeX + 1, relativeY + 1, z);
    }
}

void NumericBox::notify(string text)
{
    if (text == " + ")
    {
        increase();
    }
    else
    {
        decrease();
    }
}
