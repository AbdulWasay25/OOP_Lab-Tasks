#include <iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (denominator == 0) {
            cout<<"Denominator cannot be zero."<<endl;
        }
        if (denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
    }

    int gcd(int a, int b) const {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    Fraction reduce() const {
        int g = gcd(numerator, denominator);
        return Fraction(numerator / g, denominator / g);
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + denominator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom).reduce();
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom).reduce();
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom).reduce();
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout<<"Cannot divide by zero."<<endl;
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom).reduce();
    }

    bool operator==(const Fraction& other) const {
        Fraction f1 = this->reduce();
        Fraction f2 = other.reduce();
        return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
    }

    bool operator!=(const Fraction& other) const { return !(*this == other); }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }

    bool operator>(const Fraction& other) const { return other < *this; }

    bool operator<=(const Fraction& other) const { return !(other < *this); }

    bool operator>=(const Fraction& other) const { return !(*this < other); }

    void print() const { cout << numerator << " / " << denominator; }
};

int main() {
        Fraction f1(2, 5), f2(2, 5);

        f1 = f1.reduce();
        f2 = f2.reduce();

        Fraction sum = f1.operator+(f2);

        cout << "Sum = ";
        sum.print();
        cout << endl;

        return 0;
}
