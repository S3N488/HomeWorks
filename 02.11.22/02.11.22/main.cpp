#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string file_name, search_word, replace_word;

    // Ввод имени файла, слова для поиска и слова для замены
    cout << "Введите имя файла: ";
    cin >> file_name;
    cout << "Введите слово для поиска: ";
    cin >> search_word;
    cout << "Введите слово для замены: ";
    cin >> replace_word;

    // Открытие файла для чтения
    ifstream input_file(file_name);
    if (!input_file.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    // Создание временного файла для записи результата
    string temp_file_name = "temp.txt";
    ofstream temp_file(temp_file_name);

    // Построчное чтение файла и замена искомого слова на замену
    string line;
    while (getline(input_file, line)) {
        size_t pos = line.find(search_word);
        while (pos != string::npos) {
            line.replace(pos, search_word.length(), replace_word);
            pos = line.find(search_word, pos + replace_word.length());
        }
        temp_file << line << endl;
    }

    // Закрытие файлов
    input_file.close();
    temp_file.close();

    // Удаление исходного файла и переименование временного файла
    if (remove(file_name.c_str()) != 0) {
        cout << "Ошибка удаления файла." << endl;
        return 1;
    }
    if (rename(temp_file_name.c_str(), file_name.c_str()) != 0) {
        cout << "Ошибка переименования файла." << endl;
        return 1;
    }

    cout << "Замена выполнена успешно." << endl;

    return 0;
}
