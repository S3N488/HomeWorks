#include <iostream>
#include <string>
#include "MyLinkedList.h"

int main() {
	MyLinkedList<std::string> list;
	list.append("Moscow -13 C");
	list.append("Rostov +1 C");
	list.append("Omsk -23 C");
	list.append("Saratov -7 C");
	list.append("Krasnodar +2 C");
	list.append("Taganrog 0 C");

	std::cout << "List of strings:" << std::endl;
	list.print();

	list.remove("Omsk -23 C");
	std::cout << "List of strings after removing Omsk -23 C:" << std::endl;
	list.print();

	return 0;
}
