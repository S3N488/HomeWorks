#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string file_name, search_word, replace_word;

    // ���� ����� �����, ����� ��� ������ � ����� ��� ������
    cout << "������� ��� �����: ";
    cin >> file_name;
    cout << "������� ����� ��� ������: ";
    cin >> search_word;
    cout << "������� ����� ��� ������: ";
    cin >> replace_word;

    // �������� ����� ��� ������
    ifstream input_file(file_name);
    if (!input_file.is_open()) {
        cout << "������ �������� �����." << endl;
        return 1;
    }

    // �������� ���������� ����� ��� ������ ����������
    string temp_file_name = "temp.txt";
    ofstream temp_file(temp_file_name);

    // ���������� ������ ����� � ������ �������� ����� �� ������
    string line;
    while (getline(input_file, line)) {
        size_t pos = line.find(search_word);
        while (pos != string::npos) {
            line.replace(pos, search_word.length(), replace_word);
            pos = line.find(search_word, pos + replace_word.length());
        }
        temp_file << line << endl;
    }

    // �������� ������
    input_file.close();
    temp_file.close();

    // �������� ��������� ����� � �������������� ���������� �����
    if (remove(file_name.c_str()) != 0) {
        cout << "������ �������� �����." << endl;
        return 1;
    }
    if (rename(temp_file_name.c_str(), file_name.c_str()) != 0) {
        cout << "������ �������������� �����." << endl;
        return 1;
    }

    cout << "������ ��������� �������." << endl;

    return 0;
}
