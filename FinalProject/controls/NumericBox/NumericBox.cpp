#include "./NumericBox.hpp"

NumericBox::NumericBox(short left, short top, int maxVal, int minVal, BorderDrawer *border, Color textColor, Color backgroundColor) : 
    Panel(left, top, border, textColor, backgroundColor, 0),
    title(Label(left + 7, top + 2, 1, border, textColor, backgroundColor, " 0")),
    add(Button(left + 12, top + 2, 1, 1, border, textColor, backgroundColor, " + ")),
    subtract(Button(left + 2, top + 2, 1, 1, border, textColor, backgroundColor, " - ")),
    maxVal(maxVal),
    minVal(minVal)
{
    Panel::addControl(&this->add);
    Panel::addControl(&this->subtract);
    Panel::addControl(&this->title);
}

NumericBox::~NumericBox()
{
}

void NumericBox::increase()
{
    stringstream str(title.getTitle());
    int numericVal;
    str >> numericVal;// convert string to int
    // int numericVal = atoi(title.getTitle().c_str());
    if (numericVal >= maxVal)
        return;

    ++numericVal;
    str << numericVal; // return new int to stringstream str
    title.setTitle(str.str()); //setTitle with new string
}
void NumericBox::decrease()
{
    stringstream str(title.getTitle());
    int numericVal;
    str >> numericVal;// convert string to int
    // int numericVal = atoi(title.getTitle().c_str());
    if (numericVal <= minVal)
        return;
    --numericVal;
    str << numericVal; // return new int to stringstream str
    title.setTitle(str.str()); //setTitle with new string
}

int NumericBox::getVal()
{
    return atoi(title.getTitle().c_str());
}

void NumericBox::setVal(int val)
{
    if (val > maxVal){
        val = maxVal;
    }
    if (val < minVal){
        val = minVal;
    }
    stringstream str("");
    str << val;
    title.setTitle(str.str());
}

int NumericBox::getMin()
{
    return minVal;
}
int NumericBox::setMin(int min)
{
    if (min > this->maxVal)
        return -1;

    this->minVal = min;
    return 0;
}
int NumericBox::getMax()
{
    return maxVal;
}
int NumericBox::setMax(int max)
{
    if (max < this->minVal)
        return -1;

    this->maxVal = max;
    return 0;
}
bool NumericBox::setValue(int)
{
    return true;
} //return

void NumericBox::draw(Graphics &g, int x, int y, size_t z)
{
    short relativeX, relativeY;
    if (z == 0)
    {
        Control::draw(g, x, y, z);

        relativeX = title.getLeft();
        relativeY = title.getTop();
        title.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = add.getLeft();
        relativeY = add.getTop();
        add.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = subtract.getLeft();
        relativeY = subtract.getTop();
        subtract.draw(g, relativeX + 1, relativeY + 1, z);
    }
}