#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double D, a, b, c, x1, x2;

	cin >> a >> b >> c;
	D = b * b - 4 * a * c;
		if (D == 0 && a != 0){
			x1 = (((-1) * b) / (2 * a));
			cout << x1 << endl;
		}
		else if (D > 0 && a != 0) {
			x1 = (((-1) * b - sqrt(D)) / (2 * a));
			x2 = (((-1) * b + sqrt(D)) / (2 * a));
		}
		else if (D >= 0 && b != 0)
			cout << ((-1) * c / b) << endl;
	return 0;
}
