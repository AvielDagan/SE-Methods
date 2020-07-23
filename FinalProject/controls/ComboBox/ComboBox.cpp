#include "./ComboBox.hpp"

ComboBox::ComboBox(short left,short top,short width, short height, BorderDrawer* border, Color textColor, Color BgColor, size_t layer): Panel(left, top, width, height, border, textColor, BgColor, layer)
{
}
ComboBox::~ComboBox()
{
}

void ComboBox::addLabel(Label)
{
}
void ComboBox::removeLabel(Label)
{
}
void ComboBox::setSelected(Label)
{
}
void ComboBox::onArrowPress()
{
}
void ComboBox::traverse()
{
}
void ComboBox::onChosenLabelPress(Label)
{
}

ComboBox::ComboBox()
{
}
ComboBox::~ComboBox()
{
}