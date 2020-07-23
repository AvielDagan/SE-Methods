#include "./EventEngine.hpp"
#include <iostream>
using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			_graphics.setForeground(Color::White);
			_graphics.setBackground(Color::Black);
			// cout << "inside redraw" << endl;
			for (size_t z = 0; z < 5; ++z)
			{
				// std::cout << "c.getLeft() " << c.getLeft() << std::endl;
				// std::cout << "c.getTop() " << c.getTop() << std::endl;
				// c.draw(_graphics, c.getLeft(), c.getTop(), c.getLeft(), c.getTop(), z);
				c.draw(_graphics, c.getLeft(), c.getTop(), c.getLeft(), c.getTop(), z);
			}
			redraw = false;
		}
		// cout << "after redrawwwwwwwww" << endl;

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			auto f = Control::getFocus();
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
					moveFocus(c, f);
				else
					f->keyDown(code, chr);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control *> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused); //find focused
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}