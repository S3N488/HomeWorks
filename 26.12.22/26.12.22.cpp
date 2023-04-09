#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Contact {
public:
    string fullName;
    string phoneNumber;

    Contact(const string& fullName, const string& phoneNumber)
        : fullName(fullName), phoneNumber(phoneNumber) {}

    friend ostream& operator<<(ostream& os, const Contact& contact) {
        os << contact.fullName << " - " << contact.phoneNumber;
        return os;
    }
};

class Abonent {
public:
    Abonent() {}
    Abonent(const Abonent& other) {
        // конструктор копирования
    }
    Abonent(Abonent&& other) noexcept {
        // конструктор перемещения
    }
    Abonent& operator=(const Abonent& other) {
        // оператор присваивания копированием
        return *this;
    }
    Abonent& operator=(Abonent&& other) noexcept {
        // оператор присваивания перемещением
        return *this;
    }
};

class PhoneBook {
private:
    vector<Contact> contacts_;

public:

    PhoneBook() {}
    PhoneBook(const PhoneBook& other) {
        // конструктор копирования
    }
    PhoneBook(PhoneBook&& other) noexcept {
        // конструктор перемещения
    }
    PhoneBook& operator=(const PhoneBook& other) {
        // оператор присваивания копированием
        return *this;
    }
    PhoneBook& operator=(PhoneBook&& other) noexcept {
        // оператор присваивания перемещением
        return *this;
    }

    void addContact(const Contact& contact) {
        contacts_.push_back(contact);
        cout << "Contact added: " << contact << endl;
    }

    void removeContact(int id) {
        if (id >= 0 && id < contacts_.size()) {
            cout << "Contact removed: " << contacts_[id] << endl;
            contacts_.erase(contacts_.begin() + id);
        }
        else {
            cout << "Invalid contact id" << endl;
        }
    }

    void removeContact(const string& fullName) {
        auto contactIt = std::find_if(contacts_.begin(), contacts_.end(),
            [&](const Contact& contact) { return contact.fullName == fullName; });

        if (contactIt != contacts_.end()) {
            contacts_.erase(contactIt);
            cout << "Contact with name " << fullName << " removed" << endl;
        }
        else {
            cout << "Contact with name " << fullName << " not found" << endl;
        }
    }

    void searchContact(const string& fullName) {
        auto contactIt = std::find_if(contacts_.begin(), contacts_.end(),
            [&](const Contact& contact) { return contact.fullName == fullName; });

        if (contactIt != contacts_.end()) {
            cout << "Contact found: " << *contactIt << endl;
        }
        else {
            cout << "Contact with name " << fullName << " not found" << endl;
        }
    }

    void showAllContacts() {
        if (contacts_.empty()) {
            cout << "Phone book is empty" << endl;
            return;
        }

        for (auto& contact : contacts_) {
            cout << contact << endl;
        }
    }
};
