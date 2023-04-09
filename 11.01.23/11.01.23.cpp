#include <iostream>

class MyDate {
private:
    int day;
    int month;
    int year;

public:
    // ����������� �� ���������
    MyDate() : day(1), month(1), year(1900) {}

    // ����������� � �����������
    MyDate(int d, int m, int y) : day(d), month(m), year(y) {}

    // ����������� ������� ��� �������� ���������� ���� � ������
    void setDay(int d) {
        if (month == 2 && (d > 28 || (d == 28 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))) {
            std::cout << "�������� ���������� ���� � �������" << std::endl;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && d > 30) {
            std::cout << "�������� ���������� ���� � ���� ������" << std::endl;
        }
        else if (d > 31) {
            std::cout << "�������� ���������� ���� � ���� ������" << std::endl;
        }
        else {
            day = d;
        }
    }

    // ������������� �������� ++ (�������� ���� ���� � ������ ���������� ���� � ������)
    MyDate operator++(int) {
        MyDate temp(day, month, year);
        if (day == 31 && month == 12) {
            year++;
            month = 1;
            day = 1;
        }
        else if (day == 31) {
            month++;
            day = 1;
        }
        else if (month == 2 && day == 28 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            month++;
            day = 1;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
            month++;
            day = 1;
        }
        else {
            day++;
        }
        return temp;
    }

    // ������������� �������� <<
    friend std::ostream& operator<<(std::ostream& os, const MyDate& date) {
        os << date.day << '.' << date.month << '.' << date.year;
        return os;
    }
};
