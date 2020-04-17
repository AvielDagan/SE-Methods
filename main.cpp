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

    // set init options and print menu
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
                MouseEventProc(irInBuf[i].Event.MouseEvent);
                break;

            case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
                ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
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

    // Restore input mode on exit.

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
            // printf("LEFT ARROW key");
            // textbox.draw();
            break;

        case VK_RIGHT:
            // printf("RIGHT ARROW key");
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
                checkbox1.drawOnPress(mainController.getCurrCord().Y);
                checkbox1.setColors(BACKGROUND_INTENSITY);
                checkbox1.drawBoxArea();
                break;

            default:
                break;
            }
            // return;

            break;
        case VK_UP:
            // printf("RIGHT ARROW key");
            switch (mainController.getCurrCord().Y)
            {
            case 10:

                labelCheckBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                labelTextBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
                labelTextBox.draw();
                labelCheckBox.draw();
                mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) - MENU_Y_JUMP});
                break;
            case 15: // Cursor is on the second box
                mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) - MENU_Y_JUMP});
                checkbox2.setColors(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//Unselected box - white
                checkbox2.drawBoxArea();
                checkbox1.setColors(BACKGROUND_INTENSITY);//selected box - grey
                checkbox1.drawBoxArea();
            default:
                break;
            }
            break;

        case VK_DOWN:
            switch (mainController.getCurrCord().Y)
            {
            case 5:
                labelTextBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                labelCheckBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
                labelTextBox.draw();
                labelCheckBox.draw();
                mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) + MENU_Y_JUMP});
                break;
            case 10: //Cursor is on the first checkbox
                mainController.setCurrCord({MENU_X_JUMP, (mainController.getCurrCord().Y) + MENU_Y_JUMP});
                checkbox1.setColors(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//Unselected box - white
                checkbox1.drawBoxArea();
                checkbox2.setColors(BACKGROUND_INTENSITY); //Selected box - grey
                checkbox2.drawBoxArea();
            default:
                break;
            }

            break;

        case VK_RETURN:
            //Switch case on the boxes according to Y position
            switch (mainController.getCurrCord().Y)
            {
            case 10:
                checkbox1.drawOnPress(mainController.getCurrCord().Y);
                checkbox1.setCheckedBox();
                checkbox1.drawBoxArea();
                break;
            case 15:
                checkbox2.drawOnPress(mainController.getCurrCord().Y);
                checkbox2.setCheckedBox();
                checkbox2.drawBoxArea();
                break;
            }

        default:
            break;
        }
        // if (ker.wVirtualKeyCode == 0x25)
        //     printf("LEFT ARROW pressed");
    }
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
    printf("Mouse event: ");

    switch (mer.dwEventFlags)
    {
    case 0:

        if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            printf("left button press \n");
        }
        else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
        {
            printf("right button press \n");
        }
        else
        {
            printf("button press\n");
        }
        break;
    case DOUBLE_CLICK:
        printf("double click\n");
        break;
    case MOUSE_HWHEELED:
        printf("horizontal mouse wheel\n");
        break;
    case MOUSE_MOVED:
        printf("mouse moved\n");
        break;
    case MOUSE_WHEELED:
        printf("vertical mouse wheel\n");
        break;
    default:
        printf("unknown\n");
        break;
    }
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
    // printf("Resize event\n");
    // printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}

void initMenu()
{
    Label label("Welcome :)", {OFFEST_LABLES_INPUT, 0}); // label indicate
    label.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    label.draw();

    textbox.setColors(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    textbox.drawInputArea();

    labelTextBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
    labelTextBox.draw();

    labelCheckBox.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
    labelCheckBox.draw();

    checkbox1.setColors(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    checkbox1.drawBoxArea();
    labelCheckBox1.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
    checkbox1.setLabel(labelCheckBox1);
    checkbox1.drawLabel();

    checkbox2.setColors(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    checkbox2.drawBoxArea();
    labelCheckBox2.setColors(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_INTENSITY);
    checkbox2.setLabel(labelCheckBox2);
    checkbox2.drawLabel();
}