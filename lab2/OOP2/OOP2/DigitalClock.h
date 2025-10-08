#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "DateController.h"
#include "TimeController.h"
#include "Screen.h"

class DigitalClock {
    DateController date;
    TimeController timeCtrl;
    Screen screen;

    int alarmH, alarmM;
    bool alarmSet;
public:
    DigitalClock();   // конструктор
    ~DigitalClock();  // деструктор

    void setCurrentDateTime();
    void setDate(int d, int m, int y);
    void setTime(int h, int m, int s);
    void show();

    void setAlarm(int h, int m);
    void checkAlarm();
};

#endif

