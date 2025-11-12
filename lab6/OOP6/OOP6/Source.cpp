#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
T findMin(T arr[], int n) {
    if (n <= 0) throw runtime_error("Array is empty");

    T minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}


template <typename T>
class FileLineRemover {
private:
    T inputFile;
    T outputFile;

public:
    FileLineRemover(T inFile, T outFile) : inputFile(inFile), outputFile(outFile) {}

    void removeLine(int lineNumber) {
        ifstream fin(inputFile);
        if (!fin.is_open()) {
            throw runtime_error("Cannot open input file!");
        }

        vector<string> lines;
        string temp;

        while (std::getline(fin, temp)) {
            lines.push_back(temp);
        }
        fin.close();

        if (lineNumber < 1 || lineNumber >(int)lines.size()) {
            throw out_of_range("Invalid line number!");
        }

     
        lines.erase(lines.begin() + (lineNumber - 1));

        ofstream fout(outputFile);
        if (!fout.is_open()) {
            throw runtime_error("Cannot open output file!");
        }

        for (const auto& l : lines) {
            fout << l << "\n";
        }
        fout.close();
    }
};


int main() {
    setlocale(LC_ALL, "Ukr");
    try {
        int n;
        cout << "Введiть кiлькiсть елементiв масиву: ";
        cin >> n;

        vector<double> arr(n);
        cout << "Введiть елементи масиву:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Мiнiмальний елемент: " << findMin(arr.data(), n) << endl;

        string input = "text.txt";
        string output = "output.txt";

        FileLineRemover<string> remover(input, output);

        int pos;
        cout << "\nВведiть номер рядка для видалення з файлу '" << input << "': ";
        cin >> pos;

        remover.removeLine(pos);

        cout << "Рядок успiшно видалено!\n";
        cout << "Результат збережено у файлi '" << output << "'.\n";
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}


