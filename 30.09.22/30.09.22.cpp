#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    std::string last_name;
    std::string first_name;
    std::string patronymic;
    std::string date_of_birth;
    std::string specialty;
    int attendance;
    int total_classes;
};

void display_student(const Student& s) {
    cout << s.specialty << " " 
         << s.last_name << " " 
         << s.first_name << " " 
         << s.patronymic << " born on " 
         << s.date_of_birth << " attended " 
         << s.attendance << " lectures out of " 
         << s.total_classes << "." << endl;
}

void add_student(vector<Student>& students, const Student& s) {
    students.push_back(s);
}

void remove_student(vector<Student>& students, int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            break;
        }
    }
}

void display_all_students(const vector<Student>& students) {
    cout << "Students list:" << endl;
    for (const auto& s : students) {
        display_student(s);
    }
}

void main() {
    vector<Student> students;

    //Добавление студентов
    add_student(students, { 1, "Ivanov", "Semyon", "Petrovich", "30.04.1998", "Engineer", 3, 5 });
    add_student(students, { 2, "Antonova", "Anna", "Ivanovna", "13.01.1999", "Designer", 7, 7 });
    add_student(students, { 3, "Mitrokhin", "Alexey", "Ivanovich", "14.08.1997", "Architect", 0, 7 });
    add_student(students, { 4, "Pavlov", "Sergey", "Alexandrovich", "08.09.1998", "Designer", 6, 7 });
    add_student(students, { 5, "Sidorov", "Mihail", "Semyonovich", "15.06.1999", "Engineer", 4, 7 });

    //Вывод студентов
    display_all_students(students);

    //Удаление по ID
    remove_student(students, 2);

    //Вывод студентов
    display_all_students(students);
}
