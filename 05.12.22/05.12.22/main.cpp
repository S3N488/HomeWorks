#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    void input() {
        cout << "Enter the numerator: ";
        cin >> numerator;
        cout << "Enter the denominator: ";
        cin >> denominator;
    }

    void display() {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(Fraction f) {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator-(Fraction f) {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator*(Fraction f) {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator/(Fraction f) {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }
};

int main() {
    Fraction f1, f2;
    f1.input();
    f2.input();

    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    cout << "f1 = ";
    f1.display();
    cout << "f2 = ";
    f2.display();
    cout << "f1 + f2 = ";
    f3.display();
    cout << "f1 - f2 = ";
    f4.display();
    cout << "f1 * f2 = ";
    f5.display();
    cout << "f1 / f2 = ";
    f6.display();

    return 0;
}
