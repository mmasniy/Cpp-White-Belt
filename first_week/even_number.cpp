#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;
	if (a <= b && a >= 1 && b <= 30000) {
		for (; a <= b; ++a) {
			if (a % 2 == 0)
				cout << a << " ";	
		}
		cout << endl;
	}
}
