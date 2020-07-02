#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
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

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int new_numerator, new_denominator;;

    if (stream) {
        stream >> new_numerator;
    }
    else 
        return stream;
    stream.ignore(1);
    if (stream) {
        stream >> new_denominator;
    }
    else
        return stream;
    rational = {new_numerator, new_denominator};
    return stream;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational{lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational{lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int lcm_denominator = lcm(lhs.Denominator(), rhs.Denominator());
    int l_multiplier = lcm_denominator / lhs.Denominator();
    int r_multiplier = lcm_denominator / rhs.Denominator();
    
    return Rational{lhs.Numerator() * l_multiplier - rhs.Numerator()
                    * r_multiplier, lcm_denominator};
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int lcm_denominator = lcm(lhs.Denominator(), rhs.Denominator());
    int l_multiplier = lcm_denominator / lhs.Denominator();
    int r_multiplier = lcm_denominator / rhs.Denominator();
    
    return Rational{lhs.Numerator() * l_multiplier + rhs.Numerator()
                    * r_multiplier, lcm_denominator};
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}