#include "editText.hpp"
#include "keyHandler.hpp"



std::string maintext = "def";

void updateText(HWND hwnd){


    InvalidateRect(hwnd, NULL, false);


    PAINTSTRUCT paints;
    RECT rect;
    
    BeginPaint(hwnd, &paints);
    GetClientRect(hwnd, &rect);

    FillRect(paints.hdc, &paints.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
    
    LPCSTR text = maintext.c_str();
    int length = std::size(maintext);
                    
    DrawText(paints.hdc, text, length, &rect, 0);



    EndPaint(hwnd, &paints);
}

void keyInput(HWND hwnd, char key, kindOfInput inp)
{

    switch(inp)
    {
        case(REGULARKEYINPUT):
            {
                std::cout << std::to_string(heldKey) << std::endl;
                maintext.push_back(key);
                break;
            }
        case(DELETEINPUT):
            {
                if(size(maintext) > 0){maintext.pop_back();}
                break;
            
            }
        default:
            break;
    }
    updateText(hwnd);
}

bool isKeyDown(int key){
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}