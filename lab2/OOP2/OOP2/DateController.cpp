#include "DateController.h"
#include <iostream>
using namespace std;

DateController::DateController() : day(1), month(1), year(2000) {}
DateController::DateController(int d, int m, int y) : day(d), month(m), year(y) {}
DateController::~DateController() {
}

void DateController::set(int d, int m, int y) { day = d; month = m; year = y; }
void DateController::get(int& d, int& m, int& y) { d = day; m = month; y = year; }
void DateController::show() {
    cout << (day < 10 ? "0" : "") << day << "."
        << (month < 10 ? "0" : "") << month << "."
        << year;
}

