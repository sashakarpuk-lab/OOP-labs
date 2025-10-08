#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen() {}
Screen::~Screen() {}

void Screen::showDateTime(DateController &date, TimeController &timeCtrl) {
    date.show();
    cout << " ";
    timeCtrl.show();
    cout << endl;
}

