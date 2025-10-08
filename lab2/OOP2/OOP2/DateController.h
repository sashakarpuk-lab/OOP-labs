#ifndef DATECONTROLLER_H
#define DATECONTROLLER_H

class DateController {
    int day, month, year;
public:
    DateController();                  // �� �������������
    DateController(int d, int m, int y); // � �����������
    ~DateController();                 // ����������

    void set(int d, int m, int y);
    void get(int& d, int& m, int& y);
    void show();
};

#endif

