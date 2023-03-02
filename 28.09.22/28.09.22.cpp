#include <iostream>
#include <vector>

using namespace std;

void add_column(vector<vector<int>>& arr, int pos, vector<int> data) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].insert(arr[i].begin() + pos, data[i]);
    }
}

void remove_column(vector<vector<int>>& arr, int col_num) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].erase(arr[i].begin() + col_num);
    }
}

void task1() {
    vector<vector<int>> arr = { {1,2,3},
                                {4,5,6},
                                {7,8,9} };
    vector<int> data = { 10,11,12 };
    add_column(arr, 1, data);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void task2() {
    vector<vector<int>> arr = { {1,2,3},
                                          {4,5,6},
                                          {7,8,9} };
    remove_column(arr, 1);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void main() {
    task1();
    cout << endl;
    task2();
}

