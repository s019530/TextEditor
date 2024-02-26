#include "keyHandler.hpp"
#include "editText.hpp"


void keyHandler(HWND hwnd, WPARAM wParam)
{
    switch(wParam)
    {
        case(0x08): //delete key
            keyInput(hwnd, char(LOWORD(wParam)), DELETEINPUT);
            break;
        case(VK_SPACE):
            keyInput(hwnd, ' ', REGULARKEYINPUT);
            break;
        case(VK_RETURN):
            keyInput(hwnd, '\n', REGULARKEYINPUT);
            break;
        default:
            char c = translateKey(wParam);
            if(c != ' '){keyInput(hwnd, c, REGULARKEYINPUT);}// is a valid character
            break;
    }

}

char translateKey(WPARAM wParam)
{

    int num = wParam;

    if(isKeyDown(VK_SHIFT))
    {
        char c = capsChars[num];
        return c;
    }
    else if(isKeyDown(VK_CONTROL))
    {
        return ' ';
    }
    else if(typedChars.find(num) != typedChars.end())
    {
        char c = typedChars[num];
        return c;
    }
    return ' ';
}


