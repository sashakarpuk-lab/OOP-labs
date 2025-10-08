#include "DigitalClock.h"
#include <iostream>
#include <thread>   
#include <chrono>   
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukr");
    DigitalClock clock;

    // Встановлюємо поточний час і дату
    clock.setCurrentDateTime();
    cout << "Поточна дата i час: ";
    clock.show();

    // Запитуємо у користувача час будильника

    int h, m;
    cout << "Введiть час будильника:" << endl;
    cout << "Година (0-23): ";
    cin >> h;
    cout << "Хвилина (0-59): ";
    cin >> m;

    clock.setAlarm(h, m);

    cout << "\nОчiкування часу будильника..." << endl;

    // Цикл перевірки
    while (true) {
        clock.setCurrentDateTime(); // оновлюємо поточний час
        clock.checkAlarm();         // перевіряємо будильник
        this_thread::sleep_for(chrono::seconds(1)); // чекаємо 1 секунду
    }
     TimeController *t = new TimeController(19, 45, 30);
    t->show();
    cout << endl;

    delete t; // тут викличеться деструктор і знищить дані
    return 0;
}


