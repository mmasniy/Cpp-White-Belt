#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        int GCD = gcd(new_numerator, new_denominator);

        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
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

bool operator >(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() / (double)lhs.Denominator()) > (rhs.Numerator() / (double)rhs.Denominator());
}

bool operator <(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() / (double)lhs.Denominator()) < (rhs.Numerator() / (double)rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0)
        throw domain_error("Devision by zero");
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        (void)x;
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }
    cout << "OK" << endl;
    return 0;
}
