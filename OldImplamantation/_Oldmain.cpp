#include <windows.h>
#include <stdio.h>
#include "Label.h"
#include "TextBox.hpp"
#include "controller.hpp"
#include "Checkbox.hpp"

HANDLE hStdin;
DWORD fdwSaveOldMode;

Controller mainController({5, 5});
TextBox textbox({20, 5});

Label labelTextBox("Text Box", {5, 5});

Label labelCheckBox("Check Box", {5, 10});

Checkbox checkbox1({20, 10});
Label labelCheckBox1("Check Box1", {25, 10});

Checkbox checkbox2({20, 15});
Label labelCheckBox2("Check Box2", {25, 15});

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
void initMenu();

boolean insideCheckBox = false;

int main(VOID)
{
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    int counter = 0;

    // Get the standard input handle.

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        ErrorExit("GetStdHandle");

    // Save the current input mode, to be restored on exit.

    if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
        ErrorExit("GetConsoleMode");

    // Enable the window and mouse input events.

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
        ErrorExit("SetConsoleMode");

    // Loop to read and handle the next 100 input events.

    // set init options and print the menu 
    initMenu();

    // Dispatch the events to the appropriate handler.
    while (1)
    {
        if (!ReadConsoleInput(
                hStdin,     // input buffer handle
                irInBuf,    // buffer to read into
                128,        // size of read buffer
                &cNumRead)) // number of records read
            ErrorExit("ReadConsoleInput");

        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case KEY_EVENT: // keyboard input
                KeyEventProc(irInBuf[i].Event.KeyEvent);
                break;

            case MOUSE_EVENT: // mouse input
                break;

            case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
                break;

            case FOCUS_EVENT: // disregard focus events

            case MENU_EVENT: // disregard menu events
                break;

            default:
                ErrorExit("Unknown event type");
                break;
            }
        }

        // Restore input mode on exit.

        SetConsoleMode(hStdin, fdwSaveOldMode);
    }
    return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
    fprintf(stderr, "%s\n", lpszMessage);

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{

    if (ker.bKeyDown) // if key pressed
    {
        switch (ker.wVirtualKeyCode)
        {
        case VK_LEFT:
            if (insideCheckBox)
            {
                insideCheckBox = false;
                labelCheckBox.setColors(WHITE_FOREGROUND_COLOR, SELECTED_BACKGROUND);
                checkbox1.setColors(0, WHITE_BACKGROUND_COLOR);
                checkbox2.setColors(0, WHITE_BACKGROUND_COLOR);
                checkbox1.drawBoxArea();
                checkbox2.drawBoxArea();
                labelCheckBox.draw();
                mainController.setCurrCord({5, 10});
            }
            break;

        case VK_RIGHT:
            break;

        case VK_TAB:
            switch (mainController.getCurrCord().Y)
            {
            case TEXT_BOX_Y_POSITION:
                textbox.drawInputArea();
                textbox.drawInput(mainController.getCurrCord().Y);
                break;

            case CHECK_BOX_Y_POSITION:
                //Should be another switch case on different boxes position
                labelCheckBox.setColors(WHITE_FOREGROUND_COLOR);
                labelCheckBox.draw();
                checkbox1.drawOnPress(mainController.getCurrCord().Y);
                checkbox1.setColors(0, SELECTED_BACKGROUND);
                checkbox1.drawBoxArea();
                insideCheckBox = true;
                break;

            default:
                break;
            }

            break;
        case VK_UP:
            switch (mainController.getCurrCord().Y)
            {
            case 10:
                if (!insideCheckBox)
                {
                    labelCheckBox.setColors(WHITE_FOREGROUND_COLOR);
                    labelTextBox.setColors(WHITE_FOREGROUND_COLOR, SELECTED_BACKGROUND);
                    labelTextBox.draw();
                    labelCheckBox.draw();
                    mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) - MENU_Y_JUMP});
                }
                break;
            case 15: // Cursor is on the second box
                if (insideCheckBox)
                {
                    mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) - MENU_Y_JUMP});
                    checkbox2.setColors(0, WHITE_BACKGROUND_COLOR); //Unselected box - white
                    checkbox2.drawBoxArea();
                    checkbox1.setColors(0, SELECTED_BACKGROUND); //selected box - grey
                    checkbox1.drawBoxArea();
                }
            default:
                break;
            }
            break;

        case VK_DOWN:
            switch (mainController.getCurrCord().Y)
            {
            case 5:
                if (!insideCheckBox)
                {
                    labelCheckBox.setColors(WHITE_FOREGROUND_COLOR, SELECTED_BACKGROUND);
                    labelTextBox.setColors(WHITE_FOREGROUND_COLOR, 0);
                    labelTextBox.draw();
                    labelCheckBox.draw();
                    mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) + MENU_Y_JUMP});
                }
                break;
            case 10: //Cursor is on the first checkbox
                if (insideCheckBox)
                {
                    mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) + MENU_Y_JUMP});
                    checkbox1.setColors(0, WHITE_BACKGROUND_COLOR); //Unselected box - white
                    checkbox1.drawBoxArea();
                    checkbox2.setColors(0, SELECTED_BACKGROUND); //Selected box - grey
                    checkbox2.drawBoxArea();
                }
            default:
                break;
            }

            break;

        case VK_RETURN: //Enter
            //Switch case on the boxes according to Y position
            switch (mainController.getCurrCord().Y)
            {
            case 10:
                if (insideCheckBox)
                {
                    checkbox1.drawOnPress(mainController.getCurrCord().Y);
                    checkbox1.setCheckedBox();
                    checkbox1.drawBoxArea();
                }
                break;
            case 15:
                if (insideCheckBox)
                {
                    checkbox2.drawOnPress(mainController.getCurrCord().Y);
                    checkbox2.setCheckedBox();
                    checkbox2.drawBoxArea();
                }
                break;
            }

        default:
            break;
        }
    }
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr) // for future planning
{
    // printf("Resize event\n");
    // printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}

void initMenu()
{
    Label label("Welcome :)", {OFFEST_LABLES_INPUT, 1}); // label indicate
    label.setColors(WHITE_FOREGROUND_COLOR);
    label.draw();

    Label instractions("* Up and down to move between the lables ", {OFFEST_LABLES_INPUT*2, 0}); // label indicate    
    instractions.setColors(WHITE_FOREGROUND_COLOR);
    instractions.draw();

    Label instractions2("* Tab to enter text, Enter to fill text, Left to back menu", {OFFEST_LABLES_INPUT*2, 2});
    
    instractions2.setColors(WHITE_FOREGROUND_COLOR);
    instractions2.draw();

    /**
 * WHITE_FOREGROUND_COLOR, BACKGROUND_INTENSITY
 * 
*/
    textbox.setColors(0, WHITE_BACKGROUND_COLOR);
    textbox.drawInputArea();

    labelTextBox.setColors(WHITE_FOREGROUND_COLOR, SELECTED_BACKGROUND);
    labelTextBox.draw();

    labelCheckBox.setColors(WHITE_FOREGROUND_COLOR, 0);
    labelCheckBox.draw();

    checkbox1.setColors(0, WHITE_BACKGROUND_COLOR);
    checkbox1.drawBoxArea();
    labelCheckBox1.setColors(WHITE_FOREGROUND_COLOR);
    checkbox1.setLabel(labelCheckBox1);
    checkbox1.drawLabel();

    checkbox2.setColors(0, WHITE_BACKGROUND_COLOR);
    checkbox2.drawBoxArea();
    labelCheckBox2.setColors(WHITE_FOREGROUND_COLOR);
    checkbox2.setLabel(labelCheckBox2);
    checkbox2.drawLabel();
}