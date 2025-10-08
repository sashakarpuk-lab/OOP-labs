#include "DigitalClock.h"
#include <iostream>
#include <ctime>
using namespace std;

DigitalClock::DigitalClock() : alarmH(0), alarmM(0), alarmSet(false) {}
DigitalClock::~DigitalClock() {

}

void DigitalClock::setCurrentDateTime() {
    time_t now = time(nullptr);
    tm ltm;
    localtime_s(&ltm, &now);

    date.set(ltm.tm_mday, ltm.tm_mon + 1, ltm.tm_year + 1900);
    timeCtrl.set(ltm.tm_hour, ltm.tm_min, ltm.tm_sec);
}

void DigitalClock::setDate(int d, int m, int y) { date.set(d, m, y); }
void DigitalClock::setTime(int h, int m, int s) { timeCtrl.set(h, m, s); }

void DigitalClock::show() {
    screen.showDateTime(date, timeCtrl);
}

void DigitalClock::setAlarm(int h, int m) {
    alarmH = h; alarmM = m; alarmSet = true;
    cout << "Будильник встановлено на ";
    if (h < 10) cout << "0";
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m << endl;
}

void DigitalClock::checkAlarm() {
    int h, m, s;
    timeCtrl.get(h, m, s);
    if (alarmSet && h == alarmH && m == alarmM) {
        cout << "Будильник спрацював!" << endl;
        alarmSet = false;
    }
}

