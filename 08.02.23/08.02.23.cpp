#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

// Функция для удаления знаков пунктуации из строки
void remove_punctuation(std::string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
}

int main() {
    std::string filename_in = "input.txt";
    std::string filename_out = "output.txt";

    // Открываем файл для чтения
    std::ifstream fin(filename_in);
    if (!fin) {
        std::cerr << "Error opening file: " << filename_in << std::endl;
        return 1;
    }

    // Создаем частотный словарь
    std::map<std::string, int> word_freq;

    // Считываем текст по словам и заполняем словарь
    std::string word;
    while (fin >> word) {
        // Удаляем знаки пунктуации из слова
        remove_punctuation(word);

        // Приводим слово к нижнему регистру
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Увеличиваем счетчик частоты для данного слова
        ++word_freq[word];
    }

    // Закрываем файл
    fin.close();

    // Открываем файл для записи
    std::ofstream fout(filename_out);
    if (!fout) {
        std::cerr << "Error opening file: " << filename_out << std::endl;
        return 1;
    }

    // Выводим информацию обо всех словах
    for (auto& pair : word_freq) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        fout << pair.first << ": " << pair.second << std::endl;
    }

    // Находим наиболее часто встречающееся слово
    std::string most_common_word;
    int max_freq = 0;
    for (auto& pair : word_freq) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            most_common_word = pair.first;
        }
    }

    // Выводим информацию о наиболее часто встречающемся слове
    std::cout << "Most common word: " << most_common_word << ", frequency: " << max_freq << std::endl;
    fout << "Most common word: " << most_common_word << ", frequency: " << max_freq << std::endl;

    // Закрываем файл
    fout.close();

    return 0;
}
