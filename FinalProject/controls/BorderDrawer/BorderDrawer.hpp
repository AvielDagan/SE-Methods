#pragma once

#include "../Graphics/Graphics.hpp"


struct BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const = 0;
};
class SingleBorderDrawer : public BorderDrawer {};

class DoubleBorderDrawer : public BorderDrawer {};

class NullBorderDrawer : public BorderDrawer {};