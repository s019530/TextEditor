#include "editText.hpp"
#include "keyHandler.hpp"



std::string maintext = "\n\n\n Start Of File";//TEMPORARY FIX TO OFFSET TEXT, NEEDS A PROPER SOLUTION

int fontSize = 16;

HFONT fon = CreateFont(fontSize, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");

void updateText(HWND hwnd){

    drawBackground(hwnd);//TEMPORARY FIX TO OFFSET TEXT, NEEDS A PROPER SOLUTION

    InvalidateRect(hwnd, NULL, false);


    PAINTSTRUCT paints;
    RECT rect;

    if(size(maintext) < 3)
    {
        maintext = "\n\n\n";//TEMPORARY FIX TO OFFSET TEXT, NEEDS A PROPER SOLUTION
    }
    
    BeginPaint(hwnd, &paints);
    GetClientRect(hwnd, &rect);

    LPCSTR text = maintext.c_str();
    int length = std::size(maintext);

    SetBkMode(paints.hdc, TRANSPARENT);
    

    SelectObject(paints.hdc, fon);

    DrawText(paints.hdc, text, length, &rect, DT_WORDBREAK);



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
    

    RECT rect;
    SetRect(&rect, paints.rcPaint.left, 45, paints.rcPaint.right, paints.rcPaint.bottom);
        
    FillRect(paints.hdc, &rect, CreateSolidBrush(RGB(151,213, 232)));

    for(long i = 61; i <= paints.rcPaint.bottom; i += fontSize)
    {
        Rectangle(paints.hdc, paints.rcPaint.left, i, paints.rcPaint.right, i+1);
    }
    
    EndPaint(hwnd, &paints);

}