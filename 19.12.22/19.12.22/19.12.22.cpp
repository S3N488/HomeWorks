#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction() : numerator_(0), denominator_(1) {}
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.numerator_ << "/" << fraction.denominator_;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& fraction) {
        is >> fraction.numerator_;
        char separator;
        is >> separator;
        if (separator != '/') {
            is.setstate(ios::failbit);
            return is;
        }
        is >> fraction.denominator_;
        return is;
    }

    Fraction operator+(const Fraction& other) const {
        int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator_ * other.numerator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        int newNumerator = numerator_ * other.denominator_;
        int newDenominator = denominator_ * other.numerator_;
        return Fraction(newNumerator, newDenominator);
    }

private:
    int numerator_;
    int denominator_;
};

int main() {
    Fraction f1, f2;
    cout << "Enter fraction 1 in the form a/b: ";
    cin >> f1;
    cout << "Enter fraction 2 in the form a/b: ";
    cin >> f2;

    cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
    cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
    cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
    cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;

    return 0;
}
