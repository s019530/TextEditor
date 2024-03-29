#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <unordered_map>
#include <map>

static int heldKey;

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

static std::map<int, char> capsChars = {
  {48, ')'},
  {49, '!'},
  {50, '@'},
  {51, '#'},
  {52, '$'},
  {53, '%'},
  {54, '^'},
  {55, '&'},
  {56, '*'},
  {57, '('},
  {65, 'A'},
  {66, 'B'},
  {67, 'C'},
  {68, 'D'},
  {69, 'E'},
  {70, 'F'},
  {71, 'G'},
  {72, 'H'},
  {73, 'I'},
  {74, 'J'},
  {75, 'K'},
  {76, 'L'},
  {77, 'M'},
  {78, 'N'},
  {79, 'O'},
  {80, 'P'},
  {81, 'Q'},
  {82, 'R'},
  {83, 'S'},
  {84, 'T'},
  {85, 'U'},
  {86, 'V'},
  {87, 'W'},
  {88, 'X'},
  {89, 'Y'},
  {90, 'Z'},
  {188, '<'},
  {190, '>'},
  {191, '?'},
  {186, ':'},
  {222, '\"'},
  {219, '{'},
  {221, '}'},
  {189, '_'},
  {187, '+'}
};


void keyHandler(HWND hwnd, WPARAM wParam);

char translateKey(WPARAM wParam);