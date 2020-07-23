#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
public:
	
	void clearScreen();
	void moveTo(int x, int y);
	void setBackground(Color color);
	void setForeground(Color color);
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);
	void setCursorVisibility(bool isVisible);
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	~Graphics();
private:
	HANDLE _console;
	Color _background, _foreground;

	void updateConsoleAttributes();
};

bool isInside(int x, int y, int left, int top, int width, int height);