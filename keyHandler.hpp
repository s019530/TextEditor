#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <unordered_map>
#include <map>


static std::map<int, char> typedChars = {
  {48, '0'},
  {49, '1'},
  {50, '2'},
  {51, '3'},
  {52, '4'},
  {53, '5'},
  {54, '6'},
  {55, '7'},
  {56, '8'},
  {57, '9'},
  {65, 'a'},
  {66, 'b'},
  {67, 'c'},
  {68, 'd'},
  {69, 'e'},
  {70, 'f'},
  {71, 'g'},
  {72, 'h'},
  {73, 'i'},
  {74, 'j'},
  {75, 'k'},
  {76, 'l'},
  {77, 'm'},
  {78, 'n'},
  {79, 'o'},
  {80, 'p'},
  {81, 'q'},
  {82, 'r'},
  {83, 's'},
  {84, 't'},
  {85, 'u'},
  {86, 'v'},
  {87, 'w'},
  {88, 'x'},
  {89, 'y'},
  {90, 'z'},
  {188, ','},
  {190, '.'},
  {191, '/'},
  {186, ';'},
  {222, '\''},
  {219, '['},
  {221, ']'},
  {189, '-'},
  {187, '='}
};

void keyHandler(HWND hwnd, WPARAM wParam);

char translateKey(WPARAM wParam);