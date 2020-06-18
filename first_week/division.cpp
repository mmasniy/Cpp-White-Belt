#include <iostream>

using namespace std;

int main() {
	int A, B;

	cin >> A >> B;

	if (A >= 0 && B > 0 && A <= 1000000 && B <= 1000000) {
		cout << (A / B) << endl;
	}
	else if (B == 0)
		cout << "Impossible" << endl;
	return 0;
}
