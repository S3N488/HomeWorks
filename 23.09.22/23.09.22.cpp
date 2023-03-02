#include <iostream>

using namespace std;

//Задание 1. Оформить этот код в виде удобных и аккуратных функций.
void average() {
    int num_points = 14;
    int num_dim = 2;
    double** points = new double* [num_points];

    for (int k = 0; k < num_points; k++) {
        points[k] = new double[num_dim] {};
    }

    srand(13);
    for (int k = 0; k < num_points; k++) {
        points[k][0] = rand() % 10;
        points[k][1] = rand() % 10;
    }

    cout << "Average: " << endl;
    double x = 0, y = 0;
    for (int k = 0; k < num_points; k++) {
        x += points[k][0];
        y += points[k][1];
    }

    if (num_points > 0) {
        x /= num_points;
        y /= num_points;
        cout << "(" << x << "; " << y << ")" << endl;
    }

    for (int k = 0; k < num_points; k++) {
        delete[] points[k];
    }
    delete[] points;
}

void distance_to_0() {
    int num_points = 14;
    int num_dim = 2;
    double** points = new double* [num_points];

    for (int k = 0; k < num_points; k++) {
        points[k] = new double[num_dim] {};
    }

    srand(13);
    for (int k = 0; k < num_points; k++) {
        points[k][0] = rand() % 10;
        points[k][1] = rand() % 10;
    }

    cout << "Distance to (0; 0): " << endl;
    for (int k = 0; k < num_points; k++) {
        cout << sqrt(pow(points[k][0], 2) +
            points[k][1] * points[k][1]) << endl;
    }

    for (int k = 0; k < num_points; k++) {
        delete[] points[k];
    }
    delete[] points;
}

void distance_to_x_y() {
    int num_points = 14;
    int num_dim = 2;
    double** points = new double* [num_points];

    for (int k = 0; k < num_points; k++) {
        points[k] = new double[num_dim] {};
    }

    srand(13);
    for (int k = 0; k < num_points; k++) {
        points[k][0] = rand() % 10;
        points[k][1] = rand() % 10;
    }

    double x = 0, y = 0;
    for (int k = 0; k < num_points; k++) {
        x += points[k][0];
        y += points[k][1];
    }

    if (num_points > 0) {
        x /= num_points;
        y /= num_points;
        cout << "(" << x << "; " << y << ")" << endl;
    }

    cout << "Distance to (" << x << "; " << y << "): " << endl;
    for (int k = 0; k < num_points; k++) {
        cout << sqrt(pow(points[k][0] - x, 2) +
            (points[k][1] - y) * (points[k][1] - y)) << endl;
    }

    for (int k = 0; k < num_points; k++) {
        delete[] points[k];
    }
    delete[] points;
}

void max_dist() {
    int num_points = 14;
    int num_dim = 2;
    double** points = new double* [num_points];

    for (int k = 0; k < num_points; k++) {
        points[k] = new double[num_dim] {};
    }

    srand(13);
    for (int k = 0; k < num_points; k++) {
        points[k][0] = rand() % 10;
        points[k][1] = rand() % 10;
    }

    double max_dist = 0, curr_dist;
    int id_k1, id_k2;
    for (int k1 = 0; k1 < num_points; k1++) {
        for (int k2 = k1 + 1; k2 < num_points; k2++) {
            curr_dist = distance(points[k1], points[k2]);
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
                id_k1 = k1;
                id_k2 = k2;
            }
        }
    }
    cout << "Max dist: " << endl;
    cout << "(" << points[id_k1][0] << "; " << points[id_k1][1] << ")" << endl;
    cout << "(" << points[id_k2][0] << "; " << points[id_k2][1] << ")" << endl;
    cout << max_dist << endl;

    for (int k = 0; k < num_points; k++) {
        delete[] points[k];
    }
    delete[] points;
}

void points() {
    int num_points = 14;
    int num_dim = 2;
    double** points = new double* [num_points];

    for (int k = 0; k < num_points; k++) {
        points[k] = new double[num_dim] {};
    }

    srand(13);
    for (int k = 0; k < num_points; k++) {
        points[k][0] = rand() % 10;
        points[k][1] = rand() % 10;
    }

    cout << "Points: " << endl;
    for (int k = 0; k < num_points; k++) {
        cout << "(" << points[k][0] << "; " << points[k][1]
            << ")" << endl;
    }

    for (int k = 0; k < num_points; k++) {
        delete[] points[k];
    }
    delete[] points;
}

void main() {
    average();
    distance_to_0();
    distance_to_x_y();
    max_dist();
    points();
}