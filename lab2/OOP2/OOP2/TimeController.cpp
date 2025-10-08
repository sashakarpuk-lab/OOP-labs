#include "TimeController.h"

TimeController::TimeController() {
    hours = new int(0);
    minutes = new int(0);
    seconds = new int(0);
}

TimeController::TimeController(int h, int m, int s) {
    hours = new int(h);
    minutes = new int(m);
    seconds = new int(s);
}

TimeController::~TimeController() {
    cout << "TimeController destroyed ("
        << *hours << ":" << *minutes << ":" << *seconds << ")" << endl;
    delete hours;
    delete minutes;
    delete seconds;
}

void TimeController::set(int h, int m, int s) {
    *hours = h; *minutes = m; *seconds = s;
}

void TimeController::get(int& h, int& m, int& s) {
    h = *hours; m = *minutes; s = *seconds;
}

void TimeController::show() const {
    cout << (*hours < 10 ? "0" : "") << *hours << ":"
        << (*minutes < 10 ? "0" : "") << *minutes << ":"
        << (*seconds < 10 ? "0" : "") << *seconds;
}


