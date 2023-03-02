#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void task1() {
    string s[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter student name " << i + 1 << ": ";
        cin >> s[i];
    }

    sort(s, s + 5);

    cout << "Sorted student names: ";
    for (int i = 0; i < 5; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void task2() {
    int m, n;
    cout << "Enter the size of array A: ";
    cin >> m;
    cout << "Enter the size of array B: ";
    cin >> n;

    int* a= new int[m];
    int* b= new int[n];

    cout << "Enter the elements of array A: ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    cout << "Enter the elements of array B: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            bool already_added = false;
            for (int k = 0; k < c.size(); k++) {
                if (a[i] == c[k]) {
                    already_added = true;
                    break;
                }
            }
            if (!already_added) {
                c.push_back(a[i]);
            }
        }
    }

    cout << "Array C: ";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

void main() {
    task1();
    task2();
}
