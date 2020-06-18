#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double D, a, b, c;

	cin >> a >> b >> c;
	D = b * b - 4 * a * c;
	if (a != 0) {
		if (D == 0)
			cout << (((-1) * b) / (2 * a)) << endl;
		else if (D > 0)
			cout << (((-1) * b - sqrt(D)) / (2 * a)) << " " << (((-1) * b + sqrt(D)) / (2 * a)) << endl;
	}
	else if (D >= 0 && b != 0)
		cout << ((-1) * c / b) << endl;
	return 0;
}
