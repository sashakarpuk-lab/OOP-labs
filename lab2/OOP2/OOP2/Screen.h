#ifndef SCREEN_H
#define SCREEN_H

#include "DateController.h"
#include "TimeController.h"

class Screen {
public:
    Screen();   // �����������
    ~Screen();  // ����������

    void showDateTime(DateController& date, TimeController& timeCtrl);
};

#endif


