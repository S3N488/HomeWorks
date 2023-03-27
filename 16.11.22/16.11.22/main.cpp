#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    // �������� ������ ��� ������ � ������
    ifstream inputFile("input.txt");
    ifstream blacklistFile("blacklist.txt");
    ofstream outputFile("output.txt");

    // ��������, ��� ����� ������� �������
    if (!inputFile.is_open()) {
        cout << "������ �������� ����� input.txt!" << endl;
        return 1;
    }
    if (!blacklistFile.is_open()) {
        cout << "������ �������� ����� blacklist.txt!" << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cout << "������ �������� ����� output.txt!" << endl;
        return 1;
    }

    // �������� ������ ������������ ���� � ������
    vector<string> blacklist;
    string word;
    while (blacklistFile >> word) {
        blacklist.push_back(word);
    }

    // ������ ������ �� �����, �������� ������������ ���� � ������ � ����� ����
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

    // �������� ������
    inputFile.close();
    blacklistFile.close();
    outputFile.close();

    return 0;
}
