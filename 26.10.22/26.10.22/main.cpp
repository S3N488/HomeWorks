#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void task1() {
    ifstream fin("hw2610.txt"); // открытие файла для чтения
    ofstream fout("output.txt"); // открытие файла для записи
    string line;
    int count = 0;

    // Подсчитываем количество строк в файле
    while (getline(fin, line)) {
        count++;
    }

    // Возвращаем указатель на начало файла
    fin.clear();
    fin.seekg(0, ios::beg);

    // Копируем строки из файла в выходной файл,
    // кроме последней строки
    for (int i = 0; i < count - 1; i++) {
        getline(fin, line);
        fout << line << endl;
    }

    fin.close();
    fout.close();
}

void task2() {
    ifstream fin("hw2610.txt");
    string line;
    int max_len = 0;

    // Читаем строки из файла и находим максимальную длину
    while (getline(fin, line)) {
        int len = line.length();
        if (len > max_len) {
            max_len = len;
        }
    }

    cout << "The length of the longest line is " << max_len << endl;
    fin.close();
}
int main() {
    task1();
    task2();
}
