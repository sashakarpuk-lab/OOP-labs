#include "DigitalClock.h"
#include <iostream>
#include <thread>   
#include <chrono>   
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukr");
    DigitalClock clock;

    // ������������ �������� ��� � ����
    clock.setCurrentDateTime();
    cout << "������� ���� i ���: ";
    clock.show();

    // �������� � ����������� ��� ����������

    int h, m;
    cout << "����i�� ��� ����������:" << endl;
    cout << "������ (0-23): ";
    cin >> h;
    cout << "������� (0-59): ";
    cin >> m;

    clock.setAlarm(h, m);

    cout << "\n��i������� ���� ����������..." << endl;

    // ���� ��������
    while (true) {
        clock.setCurrentDateTime(); // ��������� �������� ���
        clock.checkAlarm();         // ���������� ���������
        this_thread::sleep_for(chrono::seconds(1)); // ������ 1 �������
    }
     TimeController *t = new TimeController(19, 45, 30);
    t->show();
    cout << endl;

    delete t; // ��� ����������� ���������� � ������� ���
    return 0;
}


