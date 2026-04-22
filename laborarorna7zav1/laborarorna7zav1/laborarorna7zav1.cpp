#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    ifstream inputFile("number.txt");

    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return 1;
    }

    double number;
    double sum = 0;
    int count = 0;

    while (inputFile >> number) {
        if (number < 0) {
            sum += number;
            count++;
        }
    }

    inputFile.close();

    if (count == 0) {
        cout << "В файлі немає від’ємних чисел." << endl;
    }
    else {
        cout << "Середнє арифметичне від’ємних чисел у файлі: "
            << sum / count << endl;
    }

    return 0;
}