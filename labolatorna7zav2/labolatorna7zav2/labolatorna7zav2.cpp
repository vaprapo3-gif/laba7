#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int rows = 3;
const int cols = 3;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inFile("matrix.txt");

    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return 1;
    }

    int matrix[rows][cols];

    // Зчитуємо дані з файлу
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> matrix[i][j];
        }
    }

    inFile.close();

    cout << "Початкова матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Обробка
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = 1;
            }
        }
    }

    cout << "Результуюча матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    ofstream outFile("result2D.txt");

    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }

    outFile.close();

    return 0;
}