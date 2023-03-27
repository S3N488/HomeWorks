#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    // Открытие файлов для чтения и записи
    ifstream inputFile("input.txt");
    ifstream blacklistFile("blacklist.txt");
    ofstream outputFile("output.txt");

    // Проверка, что файлы успешно открыты
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла input.txt!" << endl;
        return 1;
    }
    if (!blacklistFile.is_open()) {
        cout << "Ошибка открытия файла blacklist.txt!" << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cout << "Ошибка открытия файла output.txt!" << endl;
        return 1;
    }

    // Загрузка списка неприемлемых слов в вектор
    vector<string> blacklist;
    string word;
    while (blacklistFile >> word) {
        blacklist.push_back(word);
    }

    // Чтение текста из файла, удаление неприемлемых слов и запись в новый файл
    string line;
    while (getline(inputFile, line)) {
        for (auto it = blacklist.begin(); it != blacklist.end(); ++it) {
            size_t pos = line.find(*it);
            while (pos != string::npos) {
                line.replace(pos, it->length(), "");
                pos = line.find(*it);
            }
        }
        outputFile << line << endl;
    }

    // Закрытие файлов
    inputFile.close();
    blacklistFile.close();
    outputFile.close();

    return 0;
}
