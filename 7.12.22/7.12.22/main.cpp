#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Contact {
public:
	Contact() : fullName(""), homePhone(""), workPhone(""), mobilePhone(""), additionalInfo("") {}
	Contact(const string& fullName, const string& homePhone, const string& workPhone, const string& mobilePhone, const string& additionalInfo)
		: fullName(fullName), homePhone(homePhone), workPhone(workPhone), mobilePhone(mobilePhone), additionalInfo(additionalInfo) {}
	~Contact() {}
	const string& getFullName() const { return fullName; }
	const string& getHomePhone() const { return homePhone; }
	const string& getWorkPhone() const { return workPhone; }
	const string& getMobilePhone() const { return mobilePhone; }
	const string& getAdditionalInfo() const { return additionalInfo; }
	void setFullName(const string& fullName) { this->fullName = fullName; }
	void setHomePhone(const string& homePhone) { this->homePhone = homePhone; }
	void setWorkPhone(const string& workPhone) { this->workPhone = workPhone; }
	void setMobilePhone(const string& mobilePhone) { this->mobilePhone = mobilePhone; }
	void setAdditionalInfo(const string& additionalInfo) { this->additionalInfo = additionalInfo; }
private:
	string fullName;
	string homePhone;
	string workPhone;
	string mobilePhone;
	string additionalInfo;
};

class PhoneBook {
public:
	void addContact(const string& fullName, const string& homePhone, const string& workPhone, const string& mobilePhone, const string& additionalInfo);
	void removeContact(const string& fullName);
	Contact* findContact(const string& fullName);
	void showAllContacts();
	void saveToFile(const string& fileName);
	void loadFromFile(const string& fileName);
	~PhoneBook() {
		for (auto& contact : contacts_) {
			delete contact;
		}
	}
private:
	vector<Contact*> contacts_;
};

void PhoneBook::addContact(const string& fullName, const string& homePhone, const string& workPhone, const string& mobilePhone, const string& additionalInfo) {
	auto newContact = new Contact(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
	contacts_.push_back(newContact);
	cout << "Contact with name " << fullName << " added" << endl;
}

void PhoneBook::removeContact(const string& fullName) {
	auto contactIt = std::find_if(contacts_.begin(), contacts_.end(), [&](const Contact* contact) {return contact->getFullName() == fullName; });

	if (contactIt != contacts_.end()) {
		delete* contactIt;
		contacts_.erase(contactIt);
		cout << "Contact with name " << fullName << " removed" << endl;
	}
	else {
		cout << "Contact with name " << fullName << " not found" << endl;
	}
}

Contact* PhoneBook::findContact(const string& fullName) {
	auto contactIt = std::find_if(contacts_.begin(), contacts_.end(), [&](const Contact* contact) {return contact->getFullName() == fullName; });

	if (contactIt != contacts_.end()) {
		return*contactIt;
	}
	else {
		return nullptr;
	}
}

void PhoneBook::showAllContacts() {
	if (contacts_.empty()) {
		cout << "Phone book is empty" << endl;
		return;
	}

	for (auto& contact : contacts_) {
		cout << "Full Name: " << contact.fullName << endl;
		cout << "Home Phone: " << contact.homePhone << endl;
		cout << "Work Phone: " << contact.workPhone << endl;
		cout << "Mobile Phone: " << contact.mobilePhone << endl;
		cout << "Extra Info: " << contact.extraInfo << endl;
		cout << endl;
	}
}


void PhoneBook::loadFromFile(const string& fileName) {
	ifstream inputFile(fileName);
	if (!inputFile) {
		cout << "Error opening file " << fileName << endl;
		return;
	}

	contacts_.clear();

	string line;
	while (getline(inputFile, line)) {
		istringstream iss(line);

		string fullName;
		iss >> fullName;

		string homePhone;
		iss >> homePhone;

		string workPhone;
		iss >> workPhone;

		string mobilePhone;
		iss >> mobilePhone;

		string additionalInfo;
		getline(iss, additionalInfo);

		Contact contact(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
		contacts_.push_back(contact);
	}

	cout << "Data loaded successfully from file " << fileName << endl;
}

int main() {
	PhoneBook phoneBook;
	while (true) {
		cout << "Enter command (1 - add contact, 2 - remove contact, 3 - search by name, 4 - show all contacts, 5 - save to file, 6 - load from file, 7 - exit): ";
		int command;
		cin >> command;

		if (command == 1) {
			string fullName, homePhone, workPhone, mobilePhone, additionalInfo;
			cout << "Enter full name: ";
			cin.ignore();
			getline(cin, fullName);
			cout << "Enter home phone: ";
			cin >> homePhone;
			cout << "Enter work phone: ";
			cin >> workPhone;
			cout << "Enter mobile phone: ";
			cin >> mobilePhone;
			cout << "Enter additional information: ";
			cin.ignore();
			getline(cin, additionalInfo);

			Contact contact(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
			phoneBook.addContact(contact);
		}
		else if (command == 2) {
			string fullName;
			cout << "Enter full name: ";
			cin.ignore();
			getline(cin, fullName);
			phoneBook.removeContact(fullName);
		}
		else if (command == 3) {
			string searchQuery;
			cout << "Enter search query: ";
			cin.ignore();
			getline(cin, searchQuery);
			phoneBook.searchByName(searchQuery);
		}
		else if (command == 4) {
			phoneBook.showAllContacts();
		}
		else if (command == 5) {
			string fileName;
			cout << "Enter file name: ";
			cin >> fileName;
			phoneBook.saveToFile(fileName);
		}
		else if (command == 6) {
			string fileName;
			cout << "Enter file name: ";
			cin >> fileName;
			phoneBook.loadFromFile(fileName);
		}
		else if (command == 7) {
			break;
		}
	}

	return 0;
}