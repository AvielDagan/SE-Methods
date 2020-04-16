#include <windows.h>
#include <stdio.h>
#include "Label.h"
#include "TextBox.hpp"

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD, TextBox);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

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

    // Wait for the events.
    TextBox textbox(" ", {20, 10});
    textbox.setColors(FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    Label label("Welcome", {5, 5});
    label.setColors(FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    label.draw();

    Label label1("Enter Val", {5, 10});
    label1.setColors(FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    label1.draw();

    Label label2("CheckBox", {5, 15});
    label2.setColors(FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    label2.draw();

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
                KeyEventProc(irInBuf[i].Event.KeyEvent, textbox);
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

VOID KeyEventProc(KEY_EVENT_RECORD ker, TextBox textbox)
{

    if (ker.bKeyDown) // if key pressed
    {
        switch (ker.wVirtualKeyCode)
        {
        case VK_LEFT:
            // printf("LEFT ARROW key");
            textbox.draw();
            break;

        case VK_RIGHT:
            // printf("RIGHT ARROW key");
            break;
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
    printf("Resize event\n");
    printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}