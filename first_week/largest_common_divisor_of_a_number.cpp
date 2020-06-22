#include <iostream>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	if (b == 0)
		return a;
	if (a > b)
		return gcd(b, (a % b));
	else
		return gcd(a, (b % a));
}

int main() {
	unsigned int A, B, GCD;

	cin >> A >> B;
	cout << gcd(A, B) << endl;
	return 0;
}
