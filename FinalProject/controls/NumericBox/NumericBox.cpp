#include "./NumericBox.hpp"

NumericBox::NumericBox(short left, short top, int maxVal, int minVal, BorderDrawer *border, Color textColor, Color backgroundColor) : 
    Panel(left, top, border, textColor, backgroundColor),
    title(Label(left + 7, top + 2, 1, border, textColor, backgroundColor, " 0")),
    add(Button(left + 12, top + 2, 1, border, textColor, backgroundColor, " + ",NULL)),
    subtract(Button(left + 2, top + 2, 1, border, textColor, backgroundColor, " - ",NULL)),
    maxVal(maxVal),
    minVal(minVal)
{
    Panel::addControl(&this->add);
    Panel::addControl(&this->subtract);
    Panel::addControl(&this->title);
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    currentCoord = {left + 1 , top + 1};
    SetConsoleCursorPosition(handle, currentCoord);
}

NumericBox::~NumericBox()
{
}
void NumericBox::increase()
{
    stringstream str(title.getValue());
    int numericVal;
    str >> numericVal;// convert string to int
    // int numericVal = atoi(title.getValue().c_str());
    if (numericVal >= maxVal)
        return;

    ++numericVal;
    str << numericVal; // return new int to stringstream str
    title.setValue(str.str()); //setValue with new string
}
void NumericBox::decrease()
{
    stringstream str(title.getValue());
    int numericVal;
    str >> numericVal;// convert string to int
    // int numericVal = atoi(title.getValue().c_str());
    if (numericVal <= minVal)
        return;
    --numericVal;
    str << numericVal; // return new int to stringstream str
    title.setValue(str.str()); //setValue with new string
}

int NumericBox::getVal()
{
    return atoi(title.getValue().c_str());
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
    title.setValue(str.str());
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
} 

void NumericBox::keyDown(int keyCode, char charecter){
    int textWidth = title.getValue().length();
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(keyCode == VK_LEFT || keyCode == VK_RIGHT){
        auto offset = currentCoord.X - this->left;
        if(offset - 1 > 0 && keyCode == VK_LEFT){
            currentCoord = { currentCoord.X - 1, currentCoord.Y };
            SetConsoleCursorPosition(handle, currentCoord);
            return;
        }

        if(offset - 1 < textWidth && keyCode == VK_RIGHT){
            currentCoord = { currentCoord.X + 1, currentCoord.Y };
            SetConsoleCursorPosition(handle, currentCoord);
            return;
        }
    }
    if(keyCode == VK_RETURN){
        //get focus - should be on "-" or "+"
        increase();
    }
}

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
