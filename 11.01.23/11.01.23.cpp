#include <iostream>

class MyDate {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор по умолчанию
    MyDate() : day(1), month(1), year(1900) {}

    // Конструктор с параметрами
    MyDate(int d, int m, int y) : day(d), month(m), year(y) {}

    // Модификатор доступа для проверки количества дней в месяце
    void setDay(int d) {
        if (month == 2 && (d > 28 || (d == 28 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))) {
            std::cout << "Неверное количество дней в феврале" << std::endl;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && d > 30) {
            std::cout << "Неверное количество дней в этом месяце" << std::endl;
        }
        else if (d > 31) {
            std::cout << "Неверное количество дней в этом месяце" << std::endl;
        }
        else {
            day = d;
        }
    }

    // Перегруженный оператор ++ (добавить один день с учетом количества дней в месяце)
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

    // Перегруженный оператор <<
    friend std::ostream& operator<<(std::ostream& os, const MyDate& date) {
        os << date.day << '.' << date.month << '.' << date.year;
        return os;
    }
};
