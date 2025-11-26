#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Book {
    string title;
    int year;
};

multimap<string, Book> library;

int inputInt(const string& msg) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x) return x;

        cout << "? Помилка! Введiть число.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void addBook() {
    string author, title;

    cin.ignore();
    cout << "Введiть автора: ";
    getline(cin, author);

    cout << "Введiть назву книги: ";
    getline(cin, title);

    int year = inputInt("Введiть рiк видання: ");

    library.insert({ author, {title, year} });

    cout << "? Книгу додано!\n";
}

void deleteBook() {
    string author, title;

    cin.ignore();
    cout << "Введiть автора: ";
    getline(cin, author);

    cout << "Введiть назву книги: ";
    getline(cin, title);

    auto range = library.equal_range(author);
    bool found = false;

    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.title == title) {
            library.erase(it);
            cout << "? Книгу видалено!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "? Книгу не знайдено.\n";
}

void searchByAuthor() {
    string author;

    cin.ignore();
    cout << "Введiть автора: ";
    getline(cin, author);

    auto range = library.equal_range(author);

    if (range.first == range.second) {
        cout << "? Книг цього автора не знайдено.\n";
        return;
    }

    cout << "? Книги автора " << author << ":\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << " - " << it->second.title << " (" << it->second.year << ")\n";
    }
}

void searchByYear() {
    int year = inputInt("Введiть рiк: ");

    bool found = false;

    for (auto& item : library) {
        if (item.second.year == year) {
            cout << item.first << ": " << item.second.title
                << " (" << year << ")\n";
            found = true;
        }
    }

    if (!found)
        cout << "? Книг цього року не знайдено.\n";
}

void printAll() {
    if (library.empty()) {
        cout << "Бiблiотека порожня.\n";
        return;
    }

    cout << "? Всi книги у бiблiотецi:\n";
    for (auto& item : library) {
        cout << item.first << ": "
            << item.second.title << " (" << item.second.year << ")\n";
    }
}

int main() {
    setlocale(LC_ALL, "Ukr");
    int choice;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати книгу\n";
        cout << "2. Видалити книгу\n";
        cout << "3. Пошук за автором\n";
        cout << "4. Пошук за роком\n";
        cout << "5. Показати всi книги\n";
        cout << "0. Вихiд\n";

        choice = inputInt("Ваш вибiр: ");

        switch (choice) {
        case 1: addBook(); break;
        case 2: deleteBook(); break;
        case 3: searchByAuthor(); break;
        case 4: searchByYear(); break;
        case 5: printAll(); break;
        case 0: cout << "Вихiд...\n"; break;
        default: cout << "? Невiрний вибiр.\n"; break;
        }

    } while (choice != 0);

    return 0;
}

