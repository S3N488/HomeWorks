#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

// ������� ��� �������� ������ ���������� �� ������
void remove_punctuation(std::string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
}

int main() {
    std::string filename_in = "input.txt";
    std::string filename_out = "output.txt";

    // ��������� ���� ��� ������
    std::ifstream fin(filename_in);
    if (!fin) {
        std::cerr << "Error opening file: " << filename_in << std::endl;
        return 1;
    }

    // ������� ��������� �������
    std::map<std::string, int> word_freq;

    // ��������� ����� �� ������ � ��������� �������
    std::string word;
    while (fin >> word) {
        // ������� ����� ���������� �� �����
        remove_punctuation(word);

        // �������� ����� � ������� ��������
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // ����������� ������� ������� ��� ������� �����
        ++word_freq[word];
    }

    // ��������� ����
    fin.close();

    // ��������� ���� ��� ������
    std::ofstream fout(filename_out);
    if (!fout) {
        std::cerr << "Error opening file: " << filename_out << std::endl;
        return 1;
    }

    // ������� ���������� ��� ���� ������
    for (auto& pair : word_freq) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        fout << pair.first << ": " << pair.second << std::endl;
    }

    // ������� �������� ����� ������������� �����
    std::string most_common_word;
    int max_freq = 0;
    for (auto& pair : word_freq) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            most_common_word = pair.first;
        }
    }

    // ������� ���������� � �������� ����� ������������� �����
    std::cout << "Most common word: " << most_common_word << ", frequency: " << max_freq << std::endl;
    fout << "Most common word: " << most_common_word << ", frequency: " << max_freq << std::endl;

    // ��������� ����
    fout.close();

    return 0;
}
