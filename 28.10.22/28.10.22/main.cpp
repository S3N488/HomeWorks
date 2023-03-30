#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // �������� ����� ��� ������
    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }

    // ������� ����������
    int num_chars = 0;
    int num_lines = 0;
    int num_vowels = 0;
    int num_consonants = 0;
    int num_digits = 0;

    string line;
    while (getline(input_file, line)) {
        num_chars += line.length();
        num_lines++;

        transform(line.begin(), line.end(), line.begin(), ::tolower);

        for (char c : line) {
            if (isalpha(c)) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    num_vowels++;
                }
                else {
                    num_consonants++;
                }
            }
            else if (isdigit(c)) {
                num_digits++;
            }
        }
    }

    // �������� ����� ��� ������
    input_file.close();

    // �������� ����� ��� ������ ����������
    ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        cerr << "Failed to open output file!" << endl;
        return 1;
    }

    // ������ ���������� � ����
    output_file << "Number of characters: " << num_chars << endl;
    output_file << "Number of lines: " << num_lines << endl;
    output_file << "Number of vowels: " << num_vowels << endl;
    output_file << "Number of consonants: " << num_consonants << endl;
    output_file << "Number of digits: " << num_digits << endl;

    // �������� ����� ��� ������ ����������
    output_file.close();

    return 0;
}
