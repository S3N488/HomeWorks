#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Header.h"
#include "Dish.h"
#include <sstream>

using namespace std;

vector<Dish> dishes;

void readDishes() {
    ifstream file("bd/dishes.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        char* name = new char[100];
        int calories, protein, fat, carbohydrates;
        sscanf(line.c_str(), "%[^;];%d;%d;%d;%d", name, &calories, &protein, &fat, &carbohydrates);

        Dish dish(name, calories, protein, fat, carbohydrates);
        dishes.push_back(dish);
        delete[] name;
    }

    file.close();
}

void printDishes(const vector<Dish>& dishes) {
    for (const auto& dish : dishes) {
        cout << dish.getName() << " (" << dish.getCalories() << " kCal): " << endl;
        cout << "  Protein: " << dish.getProtein() << " g" << endl;
        cout << "  Fat: " << dish.getFat() << " g" << endl;
        cout << "  Carbohydrates: " << dish.getCarbohydrates() << " g" << endl;
        cout << endl;
    }
}

vector<Dish> searchByName(const vector<Dish>& dishes, const string& query) {
    vector<Dish> result;

    for (const auto& dish : dishes) {
        if (strstr(dish.getName(), query.c_str())) {
            result.push_back(dish);
        }
    }

    return result;
}

vector<Dish> filterByCalories(const vector<Dish>& dishes, const int& minCalories, const int& maxCalories) {
    vector<Dish> result;

    for (const auto& dish : dishes) {
        int calories = dish.getCalories();
        if (calories >= minCalories && calories <= maxCalories) {
            result.push_back(dish);
        }
    }

    return result;
}

vector<Dish> filterByFirstLetter(const vector<Dish>& dishes, const char& letter) {
    vector<Dish> result;

    for (const auto& dish : dishes) {
        if (dish.getName()[0] == letter) {
            result.push_back(dish);
        }
    }

    return result;
}

void saveDishes(const vector<Dish>& dishes) {
    ofstream file("bd/results.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    for (const auto& dish : dishes) {
        file << dish.getName() << ";" << dish.getCalories() << ";" << dish.getProtein() << ";" << dish.getFat() << ";" << dish.getCarbohydrates() << endl;
    }

    file.close();
}

int main() {
    readDishes();

    while (true) {
        cout << "Enter command (1 - search by name, 2 - filter by calories, 3 - filter by first letter, 4 - save results, 5 - exit): ";
        int command;
        cin >> command;

        if (command == 1) {
            cout << "Enter search query: ";
            string query;
            cin >> query;

            vector<Dish> results = searchByName(query);
            printDishes(results);
        }
        else if (command == 2) {
            cout << "Enter min calories: ";
            double minCalories;
            cin >> minCalories;

            cout << "Enter max calories: ";
            double maxCalories;
            cin >> maxCalories;

            vector<Dish> results = filterByCalories(minCalories, maxCalories);
            printDishes(results);
        }
        else if (command == 3) {
            cout << "Enter first letter: ";
            char letter;
            cin >> letter;

            vector<Dish> results = filterByFirstLetter(letter);
            printDishes(results);
        }
        else if (command == 4) {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;

            saveResults(filename);
        }
        else if (command == 5) {
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}

