#include "editText.hpp"
#include "keyHandler.hpp"



std::string maintext = "def";

void updateText(HWND hwnd){

    InvalidateRect(hwnd, NULL, false);


    PAINTSTRUCT paints;
    RECT rect;

    
    
    BeginPaint(hwnd, &paints);
    GetClientRect(hwnd, &rect);

    LPCSTR text = maintext.c_str();
    int length = std::size(maintext);

    SetBkMode(paints.hdc, TRANSPARENT);

    DrawText(paints.hdc, text, length, &rect, 0);



    EndPaint(hwnd, &paints);
}

void keyInput(HWND hwnd, char key, kindOfInput inp)
{

    switch(inp)
    {
        case(REGULARKEYINPUT):
            {
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


void drawBackground(HWND hwnd)
{
    InvalidateRect(hwnd, NULL, false);

    PAINTSTRUCT paints;

    BeginPaint(hwnd, &paints);
    
    FillRect(paints.hdc, &paints.rcPaint, CreateSolidBrush(RGB(151,213, 232)));

    for(long i = 15; i <= paints.rcPaint.bottom; i += 15)
    {
        Rectangle(paints.hdc, paints.rcPaint.left, i, paints.rcPaint.right, i+1);
    }
    
    EndPaint(hwnd, &paints);

}