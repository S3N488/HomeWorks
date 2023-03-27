#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void task1() {
    ifstream fin("hw2610.txt"); // �������� ����� ��� ������
    ofstream fout("output.txt"); // �������� ����� ��� ������
    string line;
    int count = 0;

    // ������������ ���������� ����� � �����
    while (getline(fin, line)) {
        count++;
    }

    // ���������� ��������� �� ������ �����
    fin.clear();
    fin.seekg(0, ios::beg);

    // �������� ������ �� ����� � �������� ����,
    // ����� ��������� ������
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

    // ������ ������ �� ����� � ������� ������������ �����
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
