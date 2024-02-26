#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <string>

typedef enum kindOfInput{
    REGULARKEYINPUT,
    DELETEINPUT,
} kindOfInput;


void updateText(HWND hwnd);
void keyInput(HWND hwnd, char key, kindOfInput inp);

bool isKeyDown(int key);