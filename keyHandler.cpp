#include "keyHandler.hpp"
#include "editText.hpp"


void keyHandler(HWND hwnd, WPARAM wParam)
{
    std::cout << wParam << std::endl;
    switch(wParam)
    {
        case(VK_SHIFT):
            std::cout << "shift";
            keyInput(hwnd, char(LOWORD(wParam)), MODIFYINPUT);
            break;
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


    if(typedChars.find(num) != typedChars.end())
    {
        char c = typedChars[num];
        return c;
    }
    return ' ';
}


