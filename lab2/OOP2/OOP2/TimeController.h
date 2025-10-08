#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include <iostream>
using namespace std;

class TimeController {
private:
    int* hours, * minutes, * seconds; // динамічні змінні
public:
    TimeController();
    TimeController(int h, int m, int s);
    ~TimeController();

    void set(int h, int m, int s);
    void get(int& h, int& m, int& s);
    void show() const;
};

#endif


