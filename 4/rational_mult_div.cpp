#include <iostream>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        int GCD = gcd(new_numerator, new_denominator);

        if (new_denominator < 0 ^ new_numerator < 0) {
            new_denominator = abs(new_denominator);
            new_numerator = abs(new_numerator) * -1;
        }
        else {
            new_numerator = abs(new_numerator);
            new_denominator = abs(new_denominator);
        }
        numerator = new_numerator / GCD;
        denominator = new_denominator / GCD;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator; // числитель
    int denominator; // знаменатель
};

bool operator ==(const Rational& lhs, const Rational& rhs) {
    int lcm_numerator = lcm(lhs.Numerator(), rhs.Numerator());
    int lcm_denominator =  lcm(lhs.Denominator(), rhs.Denominator());

    if ((lhs.Numerator() * lcm_numerator == rhs.Numerator() * lcm_numerator)
        && (lhs.Denominator() * lcm_denominator == rhs.Denominator() * lcm_denominator))
        return true;
    return false;
}



Rational operator /(const Rational& lhs, const Rational& rhs) {
    return Rational{lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return Rational{lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    int lcm_denominator = lcm(lhs.Denominator(), rhs.Denominator());
    int l_multiplier = lcm_denominator / lhs.Denominator();
    int r_multiplier = lcm_denominator / rhs.Denominator();
    
    return Rational{lhs.Numerator() * l_multiplier - rhs.Numerator()
                    * r_multiplier, lcm_denominator};
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
    int lcm_denominator = lcm(lhs.Denominator(), rhs.Denominator());
    int l_multiplier = lcm_denominator / lhs.Denominator();
    int r_multiplier = lcm_denominator / rhs.Denominator();
    
    return Rational{lhs.Numerator() * l_multiplier + rhs.Numerator()
                    * r_multiplier, lcm_denominator};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(-15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}